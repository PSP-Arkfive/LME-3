#ifndef LME_INSTALLER_PACKAGE_H
#define LME_INSTALLER_PACKAGE_H

#include <stdint.h>

#define LME_FILE_COUNT 11
#define LME_PATH_SIZE 64

typedef struct {
    char name[LME_PATH_SIZE];
    uint32_t size;
    int offset;
} LmeFile;

typedef struct {
    int (*read)(int fd, void *buffer, unsigned size);
    int (*seek)(int fd, int offset, int whence);
} LmeReader;

int lme_select_files(uint32_t firmware, int model, LmeFile files[LME_FILE_COUNT]);
int lme_validate_package(const LmeReader *io, int fd, LmeFile files[LME_FILE_COUNT]);

#endif
