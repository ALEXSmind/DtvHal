//
// Created by n1 on 16-8-30.
//
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include "../DtvHal/DtvHal.h"
#include "com_example_n1_dtvhal_DtvHalService.h"

dtv_device_t *dtv_hal_dev = NULL;

/*
 * Class:     com_example_n1_dtvhal_DtvHalService
 * Method:    switch_to
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_example_n1_dtvhal_DtvHalService_switch_to
  (JNIEnv *env, jobject jobj, jint i){

    if(dtv_hal_dev == NULL)
    {
        return -1;
    }
    else {
        return dtv_hal_dev->switch_to(dtv_hal_dev,i);
    }

  }

/*
 * Class:     com_example_n1_dtvhal_DtvHalService
 * Method:    power_control
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_example_n1_dtvhal_DtvHalService_power_control
  (JNIEnv *env, jobject jobj, jint i){

    if(dtv_hal_dev == NULL)
    {
        return -1;
    }
    else {
        return dtv_hal_dev->power_control(dtv_hal_dev,i);
    }

  }

static inline int dtv_module_open(const struct hw_module_t* module,
        struct led_control_device_t** device)
{
	return module->methods->open(module, DTV_HARDWARE_MODULE_ID,
	        (struct hw_device_t**) device);
}

/*
 * Class:     com_example_n1_dtvhal_DtvHalService
 * Method:    init
 * Signature: ()V
 */
JNIEXPORT jint JNICALL Java_com_example_n1_dtvhal_DtvHalService_init
  (JNIEnv *env, jobject jobj){

    struct dtv_module_t *module;

	LOGE("**********start find hal *********");
	LOGE(DTV_HARDWARE_MODULE_ID);

	if (hw_get_module(DTV_HARDWARE_MODULE_ID, (const hw_module_t**) &module) == 0)
	{
		LOGI("DtvService JNI: DTV Stub found.");
		if (dtv_module_open(&module->hw_module, &dtv_hal_device) == 0)
		{
			LOGI("DtvService JNI: Got Stub operations.");
			return 0;
		}
	}

	LOGE("DtvService JNI: Get Stub operations failed.");
	return -1;
  }

/*
*some init things can do here
jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv* env = NULL;
	jint result = -1;

	if (vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK)
	{
		LOGE("GetEnv failed!");
		return result;
	}

    //++++++++some init things can do here
	//register_led_hal_jni(env);

	return JNI_VERSION_1_4;
}*/