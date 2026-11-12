#!/usr/bin/env python3
"""Build an LME flash package from the checked-in manifest."""

import pathlib
import struct
import sys


def main():
    if len(sys.argv) != 4 or sys.argv[1] not in ("620", "639", "660", "661"):
        raise SystemExit("usage: pack.py {620|639|660|661} manifest output")
    firmware, manifest, output = sys.argv[1:]
    models = {
        "620": {"02", "03", "04", "05"},
        "639": {"02", "03", "04", "05", "07", "09"},
        "660": {"02", "03", "04", "05", "07", "09", "11"},
        "661": {"02", "03", "04", "05", "07", "09", "11"},
    }[firmware]
    entries = []
    for line in pathlib.Path(manifest).read_text().splitlines():
        if not line or line.startswith("#"):
            continue
        name, source = line.split(",", 1)
        if name.startswith("/kd/pspbtjnf_") and name[13:15] not in models:
            continue
        data = pathlib.Path(source).read_bytes()
        if not data:
            raise ValueError(f"empty package file: {source}")
        encoded = name.encode("ascii")
        if len(encoded) > 255:
            raise ValueError(f"package path too long: {name}")
        entries.append((encoded, data))

    with open(output, "wb") as archive:
        archive.write(struct.pack("<I", len(entries)))
        for name, data in entries:
            archive.write(struct.pack("<IB", len(data), len(name)))
            archive.write(name)
            archive.write(data)


if __name__ == "__main__":
    main()
