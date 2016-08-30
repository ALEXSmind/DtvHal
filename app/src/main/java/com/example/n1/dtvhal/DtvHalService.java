package com.example.n1.dtvhal;

/**
 * Created by n1 on 16-8-30.
 */
public class DtvHalService {

    static DtvHalService dtvhalservice;
    public static DtvHalService getInstance() {

        if (dtvhalservice == null) {
            return dtvhalservice = new DtvHalService();
        }
        return dtvhalservice;
    }

    public DtvHalService() {
        init();
    }

//    public int switch_to(int i) {
//        int ret = _switch_to(i);
//        return ret;
//    }
//
//    public int power_control(int i){
//        int ret = _power_control(i);
//        return ret;
//    }

    static {
        System.loadLibrary("DtvHalService");   //这里的名字要和build.gradle文件里的ndk名字保持一致
    }
    private native int init();
    public native int switch_to(int i);//这个方法就是要通过jni调用实现
    public native int power_control(int i);//这个方法就是要通过jni调用实现

}
