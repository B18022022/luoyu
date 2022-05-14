#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Arduino.h>
#include "Base64.h"
#include <NTPClient.h>
#include <WiFiUdp.h>

/*************************************** Config ********************************************************/
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com"); //NTP地址
WiFiClient     espClient;                             //创建一个 WiFi 客户端
PubSubClient   mqttClient;                            //创建一个 mqtt 客户端
//OneNet MQTT 配置
const char*    mqttServer = "183.230.40.39";          //目前 Onenet mqtt服务器 的 ip地址
const uint16_t mqttPort = 6002;                       //目前 Onenet mqtt服务器 的 端口号
/************************************ 请修改以下区域 *****************************************************/
#define PRODUCT_ID    "012345"                        //产品ID，需要更改为你自己创建的产品的 ID     
#define API_KEY       "0123456789012345678901234567"  //APIKEY，需要更改为你自己创建的产品的 APIKEY
#define DEVICE_ID     "012345678"                     //设备ID，需要更改为你自己创建的产品的 设备ID

//WiFi 配置
const char* ssid     = "0123456";               //WiFi账号：需要修改为所处环境的WiFi 账号
const char* password = "0123456";                 //WiFi密码：秘密需要修改为所处环境的WiFi 密码

String mykey = "0123456789012345";                    //设定16字节字符串，与APP端保持一致
String birth = "01234567";                            //设定7字节字符串，与APP端保持一致（用于补全时间生成函数至16字节）
/******************************************************************************************************/

// AES CBC Decryption
String decrypt(String encoded_data_str, String myiv) {
  uint8_t my_key[16];
  uint8_t my_iv[16];
  for (int j = 0; j < 16; j++) {
    my_key[j] = mykey.charAt(j);
  }
  for (int k = 0; k < 16; k++) {
    my_iv[k] = myiv.charAt(k);
  }
  int input_len = encoded_data_str.length();
  char *encoded_data = const_cast<char*>(encoded_data_str.c_str());
  int len = base64_dec_len(encoded_data, input_len);
  uint8_t data[ len ];
  base64_decode((char *)data, encoded_data, input_len);

  uint8_t key[16], iv[16];
  memcpy(key, my_key, 16);
  memcpy(iv, my_iv, 16);

  int n_blocks = len / 16;

  br_aes_big_cbcdec_keys decCtx;

  br_aes_big_cbcdec_init(&decCtx, key, 16);
  br_aes_big_cbcdec_run( &decCtx, iv, data, n_blocks * 16 );

  // PKCS#7 Padding (Decryption)
  uint8_t n_padding = data[n_blocks * 16 - 1];
  len = n_blocks * 16 - n_padding;
  char plain_data[len + 1];
  memcpy(plain_data, data, len);
  plain_data[len] = '\0';

  return String(plain_data);
}

//Onenet MQTT 连接
void Onenet_MQTT_Connect() {
  int cnt = 0;
  while (!mqttClient.connected()) {
    cnt++;
    Serial.println("Connect to OneNet MQTT...");
    /* 连接 Onenet 云平台*/
    if (mqttClient.connect(DEVICE_ID, PRODUCT_ID, API_KEY)) {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("\r\nconnect success!");
      return ;
    } else {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print("Connect Fail!");
      Serial.println("Retry in 1 seconds");
      delay(1000);
    }
    if (cnt >= 10) {
      cnt = 0;
      Serial.println("Connet Failed");
      Serial.println("Please Check API_KEY and  Device ID,Product ID");
    }
  }
  return ;
}

//MQTT 消息回调函数
void callback(char* topic, byte* payload, unsigned int length) {
  int i ;
  String Open = "1";
  String Close = "0";
  char encdata[30];
  timeClient.update();
  unsigned long epochTime__5 = timeClient.getEpochTime() / 5;

  String epochTime_5__1 = (String)(epochTime__5 + 1);
  String epochTime_5__2 = (String)(epochTime__5 + 2);
  String epochTime_5 = (String)(epochTime__5 );
  String epochTime_5_1 = (String)(epochTime__5 - 1);
  String epochTime_5_2 = (String)(epochTime__5 - 2);

  String myiv__1 = birth + epochTime_5__1;
  String myiv__2 = birth + epochTime_5__2;
  String myiv = birth + epochTime_5;
  String myiv_1 = birth + epochTime_5_1;
  String myiv_2 = birth + epochTime_5_2;

  Serial.print("Message Recive: topic[");
  Serial.print(topic);
  Serial.print("],value: ");

  for ( i = 0; i < length; i++) {
    encdata[i] = (char)payload[i];
  }
  encdata[i++] = '\0';
  Serial.println(encdata);
  String decdata__1 = decrypt(encdata, myiv__1);
  String decdata__2 = decrypt(encdata, myiv__2);
  String decdata = decrypt(encdata, myiv);
  String decdata_1 = decrypt(encdata, myiv_1);
  String decdata_2 = decrypt(encdata, myiv_2);

  if (decdata__1 == Open || decdata__2 == Open || decdata == Open || decdata_1 == Open || decdata_2 == Open) {
    digitalWrite(D2, LOW);
    Serial.println("open");
  }
  else if (decdata__1 == Close || decdata__2 == Close || decdata == Close || decdata_1 == Close || decdata_2 == Close) {
    digitalWrite(D2, HIGH);
    Serial.println("close");
  }
}

void setup() {
  //#0. 配置串口
  Serial.begin (115200);
  Serial.println("\r\n\r\nESP826(MQTT)Start:  ");
  delay(100);
  //#1. 连接WIFI
  WiFi.begin(ssid, password);//连接到WiFi
  Serial.print("Wait for WiFi Connect");
  int wait_cnt = 0;
  while (WiFi.status() != WL_CONNECTED) {
    if (50 <= wait_cnt++) {
      wait_cnt = 0;
      Serial.println("\r\nConnect Fialed");
      Serial.println("Please Check Your WiFi SSID and PWD or");
      Serial.println("Reset the Device and Retry");
    }
    delay(500);
    Serial.print(".");
  }
  timeClient.begin();
  timeClient.setTimeOffset(28800); //+1区，偏移3600，+8区，偏移3600*8
  Serial.println(" ");

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D2, OUTPUT);            //设置D2引脚输出
  digitalWrite(D2, HIGH);
  //#2. 客户端设置MQTT服务器 & 回调函数
  mqttClient.setServer(mqttServer, mqttPort);
  mqttClient.setClient(espClient);
  mqttClient.setCallback(callback);
}

void loop() {
  //#3.连接 Onenet
  Onenet_MQTT_Connect();
  mqttClient.loop();
}
