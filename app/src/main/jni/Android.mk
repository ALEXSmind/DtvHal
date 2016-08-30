LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := DtvHalService.cpp
LOCAL_MODULE:= DtvHalService
include $(BUILD_SHARED_LIBRARY)