package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.content.Intent;
import android.os.Bundle;

import android.view.View;
import android.widget.Toast;


import java.io.IOException;


public class Air_conditioner extends AppCompatActivity {

    Httpconnect httpconnect = new Httpconnect();
    String dId = "930696317";
    String akey = "tphOxBmiWHjyMiRQB==YzwxZIlg=";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_air_conditioner);
        Toolbar toolbar = findViewById(R.id.air_condition_toolbar);
        toolbar.setTitle("空调设备");

    }

    public void on_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Air_conditioner.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.onSync(Air_conditioner.this, dId, akey);
    }

    public void off_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Air_conditioner.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.offSync(Air_conditioner.this, dId, akey);
    }
    public void change_mode(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Air_conditioner.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.custom1Sync(Air_conditioner.this, dId, akey);
    }
    public void wind_speed(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Air_conditioner.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.custom2Sync(Air_conditioner.this, dId, akey);
    }
    public void heat_up(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Air_conditioner.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.custom3Sync(Air_conditioner.this, dId, akey);
    }
    public void cool_down(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Air_conditioner.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.custom4Sync(Air_conditioner.this, dId, akey);
    }
    public void LRswing(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Air_conditioner.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.custom5Sync(Air_conditioner.this, dId, akey);
    }
    public void UDswing(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Air_conditioner.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.custom6Sync(Air_conditioner.this, dId, akey);
    }


    public void return_click(View view) {
        Intent intent = new Intent(Air_conditioner.this, MainActivity.class);
        startActivity(intent);
    }
}