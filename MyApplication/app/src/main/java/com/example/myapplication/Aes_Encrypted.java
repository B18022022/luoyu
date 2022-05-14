package com.example.myapplication;
import android.os.Build;

import androidx.annotation.RequiresApi;

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;


import java.util.Base64;
import java.lang.*;
import java.util.Calendar;
import java.util.TimeZone;


public class Aes_Encrypted {


    @RequiresApi(api = Build.VERSION_CODES.O)
    public static void main (String[] args) {
        try {
            Calendar now = Calendar.getInstance();
            TimeZone timeZone = now.getTimeZone();

            long totalMilliseconds = System.currentTimeMillis() + timeZone.getRawOffset();
            String bir = "1999918";
            String epochTime_5 = String.valueOf(totalMilliseconds / 5000);
            String myiv = bir + epochTime_5;
            System.out.println(myiv);
            // 密钥
            String key = "cgJfC5x3gmAlEe8M";
            byte[] mykey = key.getBytes("utf-8");
            // 偏移向量
            byte[] ivBytes = myiv.getBytes("utf-8");
            IvParameterSpec ivParameterSpec = new IvParameterSpec(ivBytes);
            String text = "0";
            SecretKeySpec keySpec = new SecretKeySpec(mykey, "AES");
            // AES加密/CBC模式/PKCS5Padding填充方式（默认）
            Cipher cipher = Cipher.getInstance("AES/CBC/PKCS5Padding");
            // 初始化
            cipher.init(Cipher.ENCRYPT_MODE, keySpec, ivParameterSpec);
            byte[] encData = cipher.doFinal(text.getBytes("utf-8"));
            // base64
            Base64.Encoder encoder = Base64.getEncoder();
            String encodedText = encoder.encodeToString(encData);
            System.out.println(encodedText);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
