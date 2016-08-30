LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := dtv.default
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_SRC_FILES := DtvHal.c
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)