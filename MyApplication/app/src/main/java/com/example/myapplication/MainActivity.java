package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    boolean flag;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

    }
    public void automatic_control_click(View view) {
        if (Interval.isFastClick()) {
            Toast.makeText(MainActivity.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return ;
        }
        SharedPreferences sp = getSharedPreferences("Flag", Context.MODE_PRIVATE);
        flag = sp.getBoolean("AutoFlag", false);
        if(!flag){
            sp.edit().putBoolean("AutoFlag", true).apply();
            //填写自动控制代码
            Toast.makeText(MainActivity.this, "自动模式开", Toast.LENGTH_SHORT).show();
        }
        else {
            sp.edit().putBoolean("AutoFlag", false).apply();
            //填写取消自动控制代码
            Toast.makeText(MainActivity.this, "自动模式关", Toast.LENGTH_SHORT).show();
        }
    }

    public void air_conditioner_click(View view) {
        Intent intent = new Intent(MainActivity.this, Air_conditioner.class);
        startActivity(intent);
    }

    public void projector_click(View view) {
        Intent intent = new Intent(MainActivity.this, Projector.class);
        startActivity(intent);
    }

    public void projection_screen_click(View view) {
        Intent intent = new Intent(MainActivity.this, Projection_screen.class);
        startActivity(intent);
    }

    public void curtain_click(View view) {
        Intent intent = new Intent(MainActivity.this, Curtain.class);
        startActivity(intent);
    }

    public void bench_power_supply_click(View view) {
        Intent intent = new Intent(MainActivity.this, Bench_power_supply.class);
        startActivity(intent);
    }

    public void computer_click(View view) {
        Intent intent = new Intent(MainActivity.this, Computer.class);
        startActivity(intent);
    }


}