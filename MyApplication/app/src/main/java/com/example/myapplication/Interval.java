package com.example.myapplication;

public class Interval {
    private static long lastClickTime;
    public synchronized static boolean isFastClick() {
        long time = System.currentTimeMillis();
        if ( time - lastClickTime < 500) {
            return true;
        }
        lastClickTime = time;
        return false;
    }
    public synchronized static boolean isFastClickonCurtain() {
        long time = System.currentTimeMillis();
        if ( time - lastClickTime < 3500) {
            return true;
        }
        lastClickTime = time;
        return false;
    }
}
