#ifndef LME_INSTALLER_H
#define LME_INSTALLER_H

#include <stdint.h>

extern char package_path[256];
extern uint32_t firmware;
extern int install_result;
extern char install_message[160];

void kernel_main(void);

#endif
