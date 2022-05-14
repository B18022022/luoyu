package com.example.myapplication;


import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;

import android.view.View;
import android.widget.Toast;


import java.io.IOException;


public class Curtain extends AppCompatActivity {

    Httpconnect httpconnect = new Httpconnect();
    String dId = "931980897";
    String akey = "s7CT3ofWtBo2hAK8rjfUT1zyMjs=";
    boolean flag;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_curtain);
        Toolbar toolbar = findViewById(R.id.curtain_toolbar);
        toolbar.setTitle("窗帘设备");

    }

    public void on_click(View view) throws IOException {
        if (Interval.isFastClickonCurtain()) {
            Toast.makeText(Curtain.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return;
        }
        SharedPreferences sp = getSharedPreferences("Flag", Context.MODE_PRIVATE);
        flag = sp.getBoolean("CurtainFlag", false);
        if (flag) {
            new AlertDialog.Builder(Curtain.this).setTitle("警告")//设置对话框标题

                    .setMessage("系统监测为开启状态，是否继续开启？")
                    .setNegativeButton("否", new DialogInterface.OnClickListener() {//添加返回按钮

                        @Override
                        public void onClick(DialogInterface dialog, int which) {//确定按钮的响应事件，点击事件没写，自己添加


                        }
                    }).setPositiveButton("是", new DialogInterface.OnClickListener() {//添加确定按钮

                        @Override
                        public void onClick(DialogInterface dialog, int which) {//响应事件，点击事件没写，自己添加
                            httpconnect.onSync(Curtain.this, dId, akey);
                        }
                    }).show();//在按键响应事件中显示此对话框
        } else {
            httpconnect.onSync(Curtain.this, dId, akey);
            sp.edit().putBoolean("CurtainFlag", true).apply();//apply才会写入xml配置文件
        }

    }

    public void off_click(View view) throws IOException {
        if (Interval.isFastClickonCurtain()) {
            Toast.makeText(Curtain.this, "发送指令过快，请稍后", Toast.LENGTH_SHORT).show();
            return;
        }
        SharedPreferences sp = getSharedPreferences("Flag", Context.MODE_PRIVATE);
        flag = sp.getBoolean("CurtainFlag", false);
        if (!flag) {
            new AlertDialog.Builder(Curtain.this).setTitle("警告")//设置对话框标题

                    .setMessage("系统监测为关闭状态，是否继续关闭？")
                    .setNegativeButton("否", new DialogInterface.OnClickListener() {//添加返回按钮

                        @Override
                        public void onClick(DialogInterface dialog, int which) {//确定按钮的响应事件，点击事件没写，自己添加


                        }
                    }).setPositiveButton("是", new DialogInterface.OnClickListener() {//添加确定按钮

                        @Override
                        public void onClick(DialogInterface dialog, int which) {//响应事件，点击事件没写，自己添加
                            httpconnect.offSync(Curtain.this, dId, akey);
                        }
                    }).show();//在按键响应事件中显示此对话框
        } else {
            httpconnect.offSync(Curtain.this, dId, akey);
            sp.edit().putBoolean("CurtainFlag", false).apply();//apply才会写入xml配置文件
        }

    }

    public void return_click(View view) {
        Intent intent = new Intent(Curtain.this, MainActivity.class);
        startActivity(intent);
    }
}