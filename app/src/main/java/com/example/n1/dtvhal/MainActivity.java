package com.example.n1.dtvhal;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {


    private DtvHalService dtvhalservice;
    private TextView message_info;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button dtv_ww = (Button) findViewById(R.id.switch_to_dtv_ww);
        WW_Button_Listener ww_button_Listener = new WW_Button_Listener();
        dtv_ww.setOnClickListener(ww_button_Listener);

        Button fm = (Button) findViewById(R.id.switch_to_fm);
        FM_Button_Listener fm_button_Listener = new FM_Button_Listener();
        fm.setOnClickListener(fm_button_Listener);

        Button dtv_tw_jp = (Button) findViewById(R.id.switch_to_dtv_tw_jp);
        TW_JP_Button_Listener tw_jp_button_Listener = new TW_JP_Button_Listener();
        dtv_tw_jp.setOnClickListener(tw_jp_button_Listener);

        Button power_on = (Button) findViewById(R.id.power_on);
        Power_ON_Button_Listener power_on_button_Listener = new Power_ON_Button_Listener();
        power_on.setOnClickListener(power_on_button_Listener);

        Button power_off = (Button) findViewById(R.id.power_off);
        Power_OFF_Button_Listener power_off_button_Listener = new Power_OFF_Button_Listener();
        power_off.setOnClickListener(power_off_button_Listener);

        message_info = (TextView) findViewById(R.id.message);

        dtvhalservice = DtvHalService.getInstance();

    }

    class WW_Button_Listener implements View.OnClickListener {

        @Override
        public void onClick(View v) {

            int ret;
            ret = dtvhalservice.switch_to(0);
            if (ret != 0) {
                message_info.setText("Message: Switch to DTV_WW Failed");
            } else {
                message_info.setText("Message: Switch to DTV_WW OK");
            }

        }
    }

    class FM_Button_Listener implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            int ret;
            ret = dtvhalservice.switch_to(1);
            if (ret != 0) {
                message_info.setText("Message: Switch to FM Failed");
            } else {
                message_info.setText("Message: Switch to FM OK");
            }
        }
    }

    class TW_JP_Button_Listener implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            int ret;
            ret = dtvhalservice.switch_to(2);
            if (ret != 0) {
                message_info.setText("Message: Switch to DTV_TW/JP Failed");
            } else {
                message_info.setText("Message: Switch to DTV_TW/JP OK");
            }
        }
    }

    class Power_ON_Button_Listener implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            int ret;
            ret = dtvhalservice.power_control(1);
            if (ret != 0) {
                message_info.setText("Message: Power ON Failed");
            } else {
                message_info.setText("Message: Power ON OK");
            }
        }
    }

    class Power_OFF_Button_Listener implements View.OnClickListener {

        @Override
        public void onClick(View v) {
            int ret;
            ret = dtvhalservice.power_control(0);
            if (ret != 0) {
                message_info.setText("Message: Power OFF Failed");
            } else {
                message_info.setText("Message: Power OFF OK");
            }
        }
    }





}
