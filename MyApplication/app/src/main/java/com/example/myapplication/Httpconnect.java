package com.example.myapplication;


import android.content.Context;
import android.os.Build;
import android.os.Looper;
import android.widget.Toast;

import androidx.annotation.RequiresApi;

import java.io.IOException;

import okhttp3.MediaType;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;

import javax.crypto.BadPaddingException;
import javax.crypto.Cipher;
import javax.crypto.IllegalBlockSizeException;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

import java.io.UnsupportedEncodingException;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;
import java.lang.*;
import java.util.Calendar;
import java.util.TimeZone;

public class Httpconnect {
    String key = "0123456789012345";               //设定16字节字符串，与前端控制端保持一致
    String bir = "0123456";                        //设定7字节字符串，与前端控制端保持一致
    byte[] mykey;
    byte[] myiv;
    {
        try {
            mykey = key.getBytes("utf-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
    }


    String open = "1";
    String close = "0";
    String custom1 = "2";
    String custom2 = "3";
    String custom3 = "4";
    String custom4 = "5";
    String custom5 = "6";
    String custom6 = "7";
    SecretKeySpec keySpec = new SecretKeySpec(mykey, "AES");

    public void onSync(Context context, String dId, String akey) {
        new Thread() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void run() {
                try {
                    Calendar now = Calendar.getInstance();
                    TimeZone timeZone = now.getTimeZone();

                    long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
                    String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
                    String iv = bir + epochTime_5;
                    myiv = iv.getBytes("utf-8");
                    IvParameterSpec ivParameterSpec = new IvParameterSpec(myiv);
                    // AES加密/CBC模式/PKCS5Padding填充方式（默认）
                    Cipher cipher = null;
                    cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                    cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);

                    byte[] encData = cipher.doFinal(open.getBytes("utf-8"));

                    // base64
                    Base64.Encoder encoder = Base64.getEncoder();
                    String encodedText = encoder.encodeToString(encData);
                    OkHttpClient client = new OkHttpClient().newBuilder()
                            .build();
                    MediaType mediaType = MediaType.parse("application/json");
                    RequestBody body = RequestBody.create(mediaType, encodedText);
                    Request request = new Request.Builder()
                            .url("https://api.heclouds.com/cmds?device_id=" + dId + "")
                            .method("POST", body)
                            .addHeader("api-key", akey)
                            .addHeader("Content-Type", "application/json")
                            .build();

                    Response response = client.newCall(request).execute();
                    final String str = response.body().string();
                    char flag = str.charAt(9);
                    Looper.prepare();
                    if (flag == '0')
                        Toast.makeText(context, "已发送开机指令", Toast.LENGTH_SHORT).show();
                    else Toast.makeText(context, "设备不在线", Toast.LENGTH_SHORT).show();
                    Looper.loop();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InvalidAlgorithmParameterException e) {
                    e.printStackTrace();
                } catch (NoSuchPaddingException e) {
                    e.printStackTrace();
                } catch (IllegalBlockSizeException e) {
                    e.printStackTrace();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                } catch (BadPaddingException e) {
                    e.printStackTrace();
                } catch (InvalidKeyException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void offSync(Context context, String dId, String akey)  {
        new Thread() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void run() {
                try {
                    Calendar now = Calendar.getInstance();
                    TimeZone timeZone = now.getTimeZone();

                    long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
                    String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
                    String iv = bir + epochTime_5;
                    myiv = iv.getBytes("utf-8");
                    IvParameterSpec ivParameterSpec = new IvParameterSpec(myiv);
                    // AES加密/CBC模式/PKCS5Padding填充方式（默认）
                    Cipher cipher = null;
                    cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                    cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);

                    byte[] encData = cipher.doFinal(close.getBytes("utf-8"));

                    // base64
                    Base64.Encoder encoder = Base64.getEncoder();
                    String encodedText = encoder.encodeToString(encData);
                    OkHttpClient client = new OkHttpClient().newBuilder()
                            .build();
                    MediaType mediaType = MediaType.parse("application/json");
                    RequestBody body = RequestBody.create(mediaType, encodedText);
                    Request request = new Request.Builder()
                            .url("https://api.heclouds.com/cmds?device_id=" + dId + "")
                            .method("POST", body)
                            .addHeader("api-key", akey)
                            .addHeader("Content-Type", "application/json")
                            .build();
                    Response response = client.newCall(request).execute();
                    final String str = response.body().string();
                    char flag = str.charAt(9);
                    Looper.prepare();
                    if (flag == '0')
                        Toast.makeText(context, "已发送关机指令", Toast.LENGTH_SHORT).show();
                    else Toast.makeText(context, "设备不在线", Toast.LENGTH_SHORT).show();
                    Looper.loop();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InvalidAlgorithmParameterException e) {
                    e.printStackTrace();
                } catch (NoSuchPaddingException e) {
                    e.printStackTrace();
                } catch (IllegalBlockSizeException e) {
                    e.printStackTrace();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                } catch (BadPaddingException e) {
                    e.printStackTrace();
                } catch (InvalidKeyException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void custom1Sync(Context context, String dId, String akey)  {
        new Thread() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void run() {
                try {
                    Calendar now = Calendar.getInstance();
                    TimeZone timeZone = now.getTimeZone();

                    long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
                    String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
                    String iv = bir + epochTime_5;
                    myiv = iv.getBytes("utf-8");
                    IvParameterSpec ivParameterSpec = new IvParameterSpec(myiv);
                    // AES加密/CBC模式/PKCS5Padding填充方式（默认）
                    Cipher cipher = null;
                    cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                    cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);

                    byte[] encData = cipher.doFinal(custom1.getBytes("utf-8"));

                    // base64
                    Base64.Encoder encoder = Base64.getEncoder();
                    String encodedText = encoder.encodeToString(encData);
                    OkHttpClient client = new OkHttpClient().newBuilder()
                            .build();
                    MediaType mediaType = MediaType.parse("application/json");
                    RequestBody body = RequestBody.create(mediaType, encodedText);
                    Request request = new Request.Builder()
                            .url("https://api.heclouds.com/cmds?device_id=" + dId + "")
                            .method("POST", body)
                            .addHeader("api-key", akey)
                            .addHeader("Content-Type", "application/json")
                            .build();
                    Response response = client.newCall(request).execute();
                    final String str = response.body().string();
                    char flag = str.charAt(9);
                    Looper.prepare();
                    if (flag == '0')
                        Toast.makeText(context, "已发送自定义1指令", Toast.LENGTH_SHORT).show();
                    else Toast.makeText(context, "设备不在线", Toast.LENGTH_SHORT).show();
                    Looper.loop();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InvalidAlgorithmParameterException e) {
                    e.printStackTrace();
                } catch (NoSuchPaddingException e) {
                    e.printStackTrace();
                } catch (IllegalBlockSizeException e) {
                    e.printStackTrace();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                } catch (BadPaddingException e) {
                    e.printStackTrace();
                } catch (InvalidKeyException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }

    public void custom2Sync(Context context, String dId, String akey)  {
        new Thread() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void run() {
                try {
                    Calendar now = Calendar.getInstance();
                    TimeZone timeZone = now.getTimeZone();

                    long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
                    String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
                    String iv = bir + epochTime_5;
                    myiv = iv.getBytes("utf-8");
                    IvParameterSpec ivParameterSpec = new IvParameterSpec(myiv);
                    // AES加密/CBC模式/PKCS5Padding填充方式（默认）
                    Cipher cipher = null;
                    cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                    cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);

                    byte[] encData = cipher.doFinal(custom2.getBytes("utf-8"));

                    // base64
                    Base64.Encoder encoder = Base64.getEncoder();
                    String encodedText = encoder.encodeToString(encData);
                    OkHttpClient client = new OkHttpClient().newBuilder()
                            .build();
                    MediaType mediaType = MediaType.parse("application/json");
                    RequestBody body = RequestBody.create(mediaType, encodedText);
                    Request request = new Request.Builder()
                            .url("https://api.heclouds.com/cmds?device_id=" + dId + "")
                            .method("POST", body)
                            .addHeader("api-key", akey)
                            .addHeader("Content-Type", "application/json")
                            .build();
                    Response response = client.newCall(request).execute();
                    final String str = response.body().string();
                    char flag = str.charAt(9);
                    Looper.prepare();
                    if (flag == '0')
                        Toast.makeText(context, "已发送自定义2指令", Toast.LENGTH_SHORT).show();
                    else Toast.makeText(context, "设备不在线", Toast.LENGTH_SHORT).show();
                    Looper.loop();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InvalidAlgorithmParameterException e) {
                    e.printStackTrace();
                } catch (NoSuchPaddingException e) {
                    e.printStackTrace();
                } catch (IllegalBlockSizeException e) {
                    e.printStackTrace();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                } catch (BadPaddingException e) {
                    e.printStackTrace();
                } catch (InvalidKeyException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }
    public void custom3Sync(Context context, String dId, String akey)  {
        new Thread() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void run() {
                try {
                    Calendar now = Calendar.getInstance();
                    TimeZone timeZone = now.getTimeZone();

                    long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
                    String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
                    String iv = bir + epochTime_5;
                    myiv = iv.getBytes("utf-8");
                    IvParameterSpec ivParameterSpec = new IvParameterSpec(myiv);
                    // AES加密/CBC模式/PKCS5Padding填充方式（默认）
                    Cipher cipher = null;
                    cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                    cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);

                    byte[] encData = cipher.doFinal(custom3.getBytes("utf-8"));

                    // base64
                    Base64.Encoder encoder = Base64.getEncoder();
                    String encodedText = encoder.encodeToString(encData);
                    OkHttpClient client = new OkHttpClient().newBuilder()
                            .build();
                    MediaType mediaType = MediaType.parse("application/json");
                    RequestBody body = RequestBody.create(mediaType, encodedText);
                    Request request = new Request.Builder()
                            .url("https://api.heclouds.com/cmds?device_id=" + dId + "")
                            .method("POST", body)
                            .addHeader("api-key", akey)
                            .addHeader("Content-Type", "application/json")
                            .build();
                    Response response = client.newCall(request).execute();
                    final String str = response.body().string();
                    char flag = str.charAt(9);
                    Looper.prepare();
                    if (flag == '0')
                        Toast.makeText(context, "已发送自定义3指令", Toast.LENGTH_SHORT).show();
                    else Toast.makeText(context, "设备不在线", Toast.LENGTH_SHORT).show();
                    Looper.loop();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InvalidAlgorithmParameterException e) {
                    e.printStackTrace();
                } catch (NoSuchPaddingException e) {
                    e.printStackTrace();
                } catch (IllegalBlockSizeException e) {
                    e.printStackTrace();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                } catch (BadPaddingException e) {
                    e.printStackTrace();
                } catch (InvalidKeyException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }
    public void custom4Sync(Context context, String dId, String akey)  {
        new Thread() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void run() {
                try {
                    Calendar now = Calendar.getInstance();
                    TimeZone timeZone = now.getTimeZone();

                    long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
                    String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
                    String iv = bir + epochTime_5;
                    myiv = iv.getBytes("utf-8");
                    IvParameterSpec ivParameterSpec = new IvParameterSpec(myiv);
                    // AES加密/CBC模式/PKCS5Padding填充方式（默认）
                    Cipher cipher = null;
                    cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                    cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);

                    byte[] encData = cipher.doFinal(custom4.getBytes("utf-8"));

                    // base64
                    Base64.Encoder encoder = Base64.getEncoder();
                    String encodedText = encoder.encodeToString(encData);
                    OkHttpClient client = new OkHttpClient().newBuilder()
                            .build();
                    MediaType mediaType = MediaType.parse("application/json");
                    RequestBody body = RequestBody.create(mediaType, encodedText);
                    Request request = new Request.Builder()
                            .url("https://api.heclouds.com/cmds?device_id=" + dId + "")
                            .method("POST", body)
                            .addHeader("api-key", akey)
                            .addHeader("Content-Type", "application/json")
                            .build();
                    Response response = client.newCall(request).execute();
                    final String str = response.body().string();
                    char flag = str.charAt(9);
                    Looper.prepare();
                    if (flag == '0')
                        Toast.makeText(context, "已发送自定义4指令", Toast.LENGTH_SHORT).show();
                    else Toast.makeText(context, "设备不在线", Toast.LENGTH_SHORT).show();
                    Looper.loop();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InvalidAlgorithmParameterException e) {
                    e.printStackTrace();
                } catch (NoSuchPaddingException e) {
                    e.printStackTrace();
                } catch (IllegalBlockSizeException e) {
                    e.printStackTrace();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                } catch (BadPaddingException e) {
                    e.printStackTrace();
                } catch (InvalidKeyException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }
    public void custom5Sync(Context context, String dId, String akey)  {
        new Thread() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void run() {
                try {
                    Calendar now = Calendar.getInstance();
                    TimeZone timeZone = now.getTimeZone();

                    long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
                    String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
                    String iv = bir + epochTime_5;
                    myiv = iv.getBytes("utf-8");
                    IvParameterSpec ivParameterSpec = new IvParameterSpec(myiv);
                    // AES加密/CBC模式/PKCS5Padding填充方式（默认）
                    Cipher cipher = null;
                    cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                    cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);

                    byte[] encData = cipher.doFinal(custom5.getBytes("utf-8"));

                    // base64
                    Base64.Encoder encoder = Base64.getEncoder();
                    String encodedText = encoder.encodeToString(encData);
                    OkHttpClient client = new OkHttpClient().newBuilder()
                            .build();
                    MediaType mediaType = MediaType.parse("application/json");
                    RequestBody body = RequestBody.create(mediaType, encodedText);
                    Request request = new Request.Builder()
                            .url("https://api.heclouds.com/cmds?device_id=" + dId + "")
                            .method("POST", body)
                            .addHeader("api-key", akey)
                            .addHeader("Content-Type", "application/json")
                            .build();
                    Response response = client.newCall(request).execute();
                    final String str = response.body().string();
                    char flag = str.charAt(9);
                    Looper.prepare();
                    if (flag == '0')
                        Toast.makeText(context, "已发送自定义5指令", Toast.LENGTH_SHORT).show();
                    else Toast.makeText(context, "设备不在线", Toast.LENGTH_SHORT).show();
                    Looper.loop();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InvalidAlgorithmParameterException e) {
                    e.printStackTrace();
                } catch (NoSuchPaddingException e) {
                    e.printStackTrace();
                } catch (IllegalBlockSizeException e) {
                    e.printStackTrace();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                } catch (BadPaddingException e) {
                    e.printStackTrace();
                } catch (InvalidKeyException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }
    public void custom6Sync(Context context, String dId, String akey)  {
        new Thread() {
            @RequiresApi(api = Build.VERSION_CODES.O)
            @Override
            public void run() {
                try {
                    Calendar now = Calendar.getInstance();
                    TimeZone timeZone = now.getTimeZone();

                    long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
                    String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
                    String iv = bir + epochTime_5;
                    myiv = iv.getBytes("utf-8");
                    IvParameterSpec ivParameterSpec = new IvParameterSpec(myiv);
                    // AES加密/CBC模式/PKCS5Padding填充方式（默认）
                    Cipher cipher = null;
                    cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
                    cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);

                    byte[] encData = cipher.doFinal(custom6.getBytes("utf-8"));

                    // base64
                    Base64.Encoder encoder = Base64.getEncoder();
                    String encodedText = encoder.encodeToString(encData);
                    OkHttpClient client = new OkHttpClient().newBuilder()
                            .build();
                    MediaType mediaType = MediaType.parse("application/json");
                    RequestBody body = RequestBody.create(mediaType, encodedText);
                    Request request = new Request.Builder()
                            .url("https://api.heclouds.com/cmds?device_id=" + dId + "")
                            .method("POST", body)
                            .addHeader("api-key", akey)
                            .addHeader("Content-Type", "application/json")
                            .build();
                    Response response = client.newCall(request).execute();
                    final String str = response.body().string();
                    char flag = str.charAt(9);
                    Looper.prepare();
                    if (flag == '0')
                        Toast.makeText(context, "已发送自定义6指令", Toast.LENGTH_SHORT).show();
                    else Toast.makeText(context, "设备不在线", Toast.LENGTH_SHORT).show();
                    Looper.loop();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (InvalidAlgorithmParameterException e) {
                    e.printStackTrace();
                } catch (NoSuchPaddingException e) {
                    e.printStackTrace();
                } catch (IllegalBlockSizeException e) {
                    e.printStackTrace();
                } catch (NoSuchAlgorithmException e) {
                    e.printStackTrace();
                } catch (BadPaddingException e) {
                    e.printStackTrace();
                } catch (InvalidKeyException e) {
                    e.printStackTrace();
                }
            }
        }.start();
    }


}
