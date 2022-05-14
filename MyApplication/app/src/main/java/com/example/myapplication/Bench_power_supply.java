package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.content.Intent;
import android.os.Bundle;

import android.view.View;
import android.widget.Toast;


import java.io.IOException;


public class Bench_power_supply extends AppCompatActivity {

    Httpconnect httpconnect = new Httpconnect();
    String dId = "931980773";
    String akey = "geu=5SaT4NxHDnHkqEYyVTsmh08=";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_bench_power_supply);
        Toolbar toolbar = findViewById(R.id.bench_power_supply_toolbar);
        toolbar.setTitle("实验台电源设备");

    }

    public void on_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Bench_power_supply.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.onSync(Bench_power_supply.this, dId, akey);
    }

    public void off_click(View view) throws IOException {
        if (Interval.isFastClick()) {
            Toast.makeText(Bench_power_supply.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        httpconnect.offSync(Bench_power_supply.this, dId, akey);
    }

    public void return_click(View view) {
        Intent intent = new Intent(Bench_power_supply.this, MainActivity.class);
        startActivity(intent);
    }
}