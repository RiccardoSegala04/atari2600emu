#ifndef __CARTRIDGE_H__
#define __CARTRIDGE_H__

#include "atari2600_conf.h"


typedef struct {
    void(*cart_write)(uint16_t address, uint8_t data);
    uint8_t(*cart_read)(uint16_t address);
} cartridge_t;

#ifdef ATARI2600_CONF_CARTRIDGE_ENABLE

#else

#endif //ATARI2600_CONF_CARTRIDGE_ENABLE

#endif //__CARTRIDGE_H__