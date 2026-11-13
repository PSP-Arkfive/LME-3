#include "package.h"

#include <stdio.h>
#include <string.h>

#define FW_620 0x06020010u
#define FW_639 0x06030910u
#define FW_660 0x06060010u
#define FW_661 0x06060110u
#define MAX_PACKAGE_FILES 64
#define MAX_FILE_SIZE (8u * 1024u * 1024u)

static int read_exact(const LmeReader *io, int fd, void *buffer, unsigned size)
{
    unsigned char *p = buffer;
    while (size) {
        int n = io->read(fd, p, size);
        if (n <= 0 || (unsigned)n > size)
            return -1;
        p += n;
        size -= (unsigned)n;
    }
    return 0;
}

int lme_select_files(uint32_t firmware, int model, LmeFile files[LME_FILE_COUNT])
{
    static const char *common[] = {
        "/kd/vshctrl_02g.prx", "/kd/dax9660.prx", "/kd/inferno.prx",
        "/kd/isotope.prx", "/kd/pulsar.prx", "/kd/horoscope.prx",
        "/kd/idmanager.prx", "/vsh/module/recovery.prx",
        "/vsh/module/satellite.prx"
    };
    const char *system;
    const char *boot;
    if (firmware != FW_620 && firmware != FW_639 &&
        firmware != FW_660 && firmware != FW_661)
        return -1;
    switch (model) {
    case 0: boot = "/kd/pspbtjnf.bin"; system = "/kd/systemctrl_01g.prx"; break;
    case 1: boot = "/kd/pspbtjnf_02g.bin"; system = "/kd/systemctrl_02g.prx"; break;
    case 2: boot = "/kd/pspbtjnf_03g.bin"; system = "/kd/systemctrl_03g.prx"; break;
    case 3: boot = "/kd/pspbtjnf_04g.bin"; system = "/kd/systemctrl_03g.prx"; break;
    case 4: boot = "/kd/pspbtjnf_05g.bin"; system = "/kd/systemctrl_05g.prx"; break;
    case 6: boot = "/kd/pspbtjnf_07g.bin"; system = "/kd/systemctrl_03g.prx"; break;
    case 8: boot = "/kd/pspbtjnf_09g.bin"; system = "/kd/systemctrl_03g.prx"; break;
    case 10: boot = "/kd/pspbtjnf_11g.bin"; system = "/kd/systemctrl_03g.prx"; break;
    default: return -1;
    }
    if ((firmware == FW_620 && model > 4) ||
        (firmware == FW_639 && model == 10))
        return -1;
    memset(files, 0, sizeof(*files) * LME_FILE_COUNT);
    strcpy(files[0].name, boot);
    strcpy(files[1].name, system);
    for (unsigned i = 0; i < sizeof(common) / sizeof(common[0]); ++i)
        strcpy(files[i + 2].name, common[i]);
    strcpy(files[11].name, "/kd/usbdev.prx");
    return 0;
}

int lme_validate_package(const LmeReader *io, int fd, LmeFile files[LME_FILE_COUNT])
{
    unsigned char raw[5], buffer[1024];
    unsigned count;
    if (io->seek(fd, 0, 0) < 0 || read_exact(io, fd, raw, 4) < 0)
        return -1;
    count = (unsigned)raw[0] | ((unsigned)raw[1] << 8) |
            ((unsigned)raw[2] << 16) | ((unsigned)raw[3] << 24);
    if (!count || count > MAX_PACKAGE_FILES)
        return -1;
    for (unsigned i = 0; i < count; ++i) {
        char name[256];
        unsigned size, remaining;
        int offset;
        if (read_exact(io, fd, raw, 5) < 0)
            return -1;
        size = (unsigned)raw[0] | ((unsigned)raw[1] << 8) |
               ((unsigned)raw[2] << 16) | ((unsigned)raw[3] << 24);
        if (!size || size > MAX_FILE_SIZE || !raw[4] ||
            read_exact(io, fd, name, raw[4]) < 0)
            return -1;
        name[raw[4]] = 0;
        if (memchr(name, 0, raw[4]))
            return -1;
        offset = io->seek(fd, 0, 1);
        if (offset < 0)
            return -1;
        for (unsigned j = 0; j < LME_FILE_COUNT; ++j) {
            if (strcmp(name, files[j].name) == 0) {
                if (files[j].size)
                    return -1;
                files[j].size = size;
                files[j].offset = offset;
            }
        }
        remaining = size;
        while (remaining) {
            unsigned n = remaining < sizeof(buffer) ? remaining : sizeof(buffer);
            if (read_exact(io, fd, buffer, n) < 0)
                return -1;
            remaining -= n;
        }
    }
    if (io->read(fd, buffer, 1) != 0)
        return -1;
    for (unsigned i = 0; i < LME_FILE_COUNT; ++i)
        if (!files[i].size)
            return -1;
    return 0;
}
