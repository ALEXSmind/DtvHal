//
// Created by n1 on 16-8-30.
//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include "DtvHal.h"
#include <hardware/hardware.h>


#define SPI_TUNER_POWER_OFF 0x00
#define SPI_TUNER_POWER_ON 0x01

#define SW_TO_DTV_WW	0x00
#define SW_TO_FM		0x01
#define SW_TO_DTV_TW_JP	0x02

#define SPI_IOC_MAGIC			'k'
#define SPI_IOC_WR_TUNER_POWER _IOW(SPI_IOC_MAGIC,6,__u8)
#define SPI_IOC_WR_DTV_FM_SWITCH _IOW(SPI_IOC_MAGIC,7,__u8)

static int switch_to(struct dtv_device *dev, int i){

    int ret = 0;
    int fd = 0;
	int arg = 0;
    printf("zjd, ioctl  test... ...\n");

    //open module
    fd = open("/dev/spidtv", O_RDWR);
    if (fd < 0)
    {
        printf("ioctl test error retcode = %d\n", fd);
        ret = -1;
    }

    switch (i) {
	case SW_TO_DTV_WW:
        arg = SW_TO_DTV_WW;
        ret = ioctl(fd, SPI_IOC_WR_DTV_FM_SWITCH,&arg);
		break;
	case SW_TO_FM:
        arg = SW_TO_FM;
        ret = ioctl(fd, SPI_IOC_WR_DTV_FM_SWITCH,&arg);
		break;
	case SW_TO_DTV_TW_JP:
        arg = SW_TO_DTV_TW_JP;
        ret = ioctl(fd, SPI_IOC_WR_DTV_FM_SWITCH,&arg);
		break;
	default:
	    ret = -1;
	    printf("ioctl test SPI_IOC_WR_DTV_FM_SWITCH no such case\n");
	    break;
    }

    if (ret < 0)
    {
		printf("ioctl test SPI_IOC_WR_DTV_FM_SWITCH error retcode = %d\n", ret);
	}
	close(fd);
    return ret;


}
static int power_control(struct dtv_device *dev, int i){


    int ret = 0;
    int fd = 0;
	int arg = 0;
    printf("zjd, ioctl  test... ...\n");

    //open module
    fd = open("/dev/spidtv", O_RDWR);
    if (fd < 0)
    {
        printf("ioctl test error retcode = %d\n", fd);
        ret = -1;
    }

    switch (i) {
	case SPI_TUNER_POWER_OFF:
        arg = SPI_TUNER_POWER_OFF;
        ret = ioctl(fd, SPI_IOC_WR_TUNER_POWER,&arg);
		break;
	case SPI_TUNER_POWER_ON:
        arg = SPI_TUNER_POWER_ON;
        ret = ioctl(fd, SPI_IOC_WR_TUNER_POWER,&arg);
		break;
	default:
	    ret = -1;
	    printf("ioctl test SPI_IOC_WR_TUNER_POWER no such case\n");
	    break;
    }

    if (ret < 0)
    {
		printf("ioctl test SPI_IOC_WR_TUNER_POWER error retcode = %d\n", ret);
	}
	close(fd);
    return ret;
}

static int dtv_close(hw_device_t *dev)
{
    if (dev) {
        free(dev);
        return 0;
    } else {
        return -1;
    }
}
static int dtv_open(const hw_module_t* module, const char __unused *id,
                            hw_device_t** device)
{
    if (device == NULL) {
        ALOGE("NULL device on open");
        return -EINVAL;
    }

    dtv_device_t *dev = malloc(sizeof(dtv_device_t));
    memset(dev, 0, sizeof(dtv_device_t));

    dev->hw_device.tag = HARDWARE_DEVICE_TAG;
    dev->hw_device.version = DTV_MODULE_API_VERSION_1_0;
    dev->hw_device.module = (struct hw_module_t*) module;
    dev->hw_device.close = dtv_close;

    dev->switch_to = switch_to;
    dev->power_control = power_control;

    *device = (hw_device_t*) dev;
    return 0;
}

static struct hw_module_methods_t dtv_module_methods = {
    .open = dtv_open,
};

dtv_module_t HAL_MODULE_INFO_SYM = {
    .hw_module = {
        .tag                = HARDWARE_MODULE_TAG,
        .module_api_version = DTV_MODULE_API_VERSION_1_0,
        .hal_api_version    = HARDWARE_HAL_API_VERSION,
        .id                 = dtv_HARDWARE_MODULE_ID,
        .name               = "Demo dtv HAL",
        .author             = "The Android Open Source Project",
        .methods            = &dtv_module_methods,
    },
};