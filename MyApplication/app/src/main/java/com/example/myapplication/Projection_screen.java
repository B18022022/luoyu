package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.content.Intent;
import android.os.Bundle;

import android.view.View;
import android.widget.Toast;


import java.io.IOException;


public class Projection_screen extends AppCompatActivity {

    Httpconnect httpconnect = new Httpconnect();
    String dId = "012345678";                            //请修改为你的设备ID
    String akey = "0123456789012345678901234567";        //请修改为你的api_key

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_projection_screen);
        Toolbar toolbar = findViewById(R.id.projection_screen_toolbar);
        toolbar.setTitle("投影屏设备");

    }

    public void on_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Projection_screen.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.onSync(Projection_screen.this, dId, akey);
    }

    public void off_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Projection_screen.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.offSync(Projection_screen.this, dId, akey);
    }

    public void return_click(View view) {
        Intent intent = new Intent(Projection_screen.this, MainActivity.class);
        startActivity(intent);
    }
}
