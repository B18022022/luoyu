package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.content.Intent;
import android.os.Bundle;

import android.view.View;
import android.widget.Toast;


import java.io.IOException;


public class Computer extends AppCompatActivity {

    Httpconnect httpconnect = new Httpconnect();
    String dId = "931980535";
    String akey = "DrjnG0l5WNN7DR9fSOn8xvvDx=g=";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_computer);
        Toolbar toolbar = findViewById(R.id.computer_toolbar);
        toolbar.setTitle("计算机设备");

    }

    public void on_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Computer.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.onSync(Computer.this, dId, akey);
    }

    public void off_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Computer.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.offSync(Computer.this, dId, akey);
    }

    public void return_click(View view) {
        Intent intent = new Intent(Computer.this, MainActivity.class);
        startActivity(intent);
    }
}