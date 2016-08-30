//
// Created by n1 on 16-8-30.
//

#ifndef DTVHAL_DTVHAL_H
#define DTVHAL_DTVHAL_H
#include <hardware/hardware.h>
#include <hardware/hw_auth_token.h>

#define DTV_MODULE_API_VERSION_1_0 HARDWARE_MODULE_API_VERSION(1, 0)

typedef struct dtv_device {

    struct hw_device_t hw_device;
    int (*switch_to)(struct dtv_device *dev, int i);
    int (*power_control)(struct dtv_device *dev, int i);

}dtv_device_t;

typedef struct dtv_module {

    struct hw_module_t hw_module;

}dtv_module_t;

#define DTV_HARDWARE_MODULE_ID "dtv"



#endif //DTVHAL_DTVHAL_H
