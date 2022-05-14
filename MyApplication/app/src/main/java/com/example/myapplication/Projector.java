package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.content.Intent;
import android.os.Bundle;

import android.view.View;
import android.widget.Toast;


import java.io.IOException;


public class Projector extends AppCompatActivity {

    Httpconnect httpconnect = new Httpconnect();
    String dId = "012345678";                            //请修改为你的设备ID
    String akey = "0123456789012345678901234567";        //请修改为你的api_key

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_projector);
        Toolbar toolbar = findViewById(R.id.projector_toolbar);
        toolbar.setTitle("投影机设备");

    }

    public void on_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Projector.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.onSync(Projector.this, dId, akey);
    }

    public void off_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Projector.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.offSync(Projector.this, dId, akey);
    }
    public void video_connect(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Projector.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.custom1Sync(Projector.this, dId, akey);
    }
    public void computer_connect(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Projector.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.custom2Sync(Projector.this, dId, akey);
    }

    public void return_click(View view) {
        Intent intent = new Intent(Projector.this, MainActivity.class);
        startActivity(intent);
    }
}
