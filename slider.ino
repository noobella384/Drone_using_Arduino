/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.11 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.11.4 or later version;
     - for iOS 1.9.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP8266WIFI_LIB_POINT
#include <ESP8266WiFi.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "RemoteXY"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "12345678"


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 56 bytes
  { 255,5,0,0,0,49,0,16,31,0,5,47,68,1,62,62,2,26,31,2,
  0,38,5,22,11,2,26,31,31,65,82,77,0,68,73,83,65,82,77,0,
  4,32,17,4,11,43,2,26,4,176,3,50,44,11,2,26 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t joystick_2_x; // from -100 to 100  
  int8_t joystick_2_y; // from -100 to 100  
  uint8_t switch_1; // =1 if switch ON and =0 if OFF 
  int8_t joystick_1_y; // =-100..100 slider position 
  int8_t joystick_1_x; // =-100..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_SWITCH_1 D3
int input_PITCH = 1500;
int input_ROLL = 1500;
int input_YAW = 1500;
int input_THROTTLE = 1100;

#include <Servo.h>

Servo channel_1;
Servo channel_2;
Servo channel_3;
Servo channel_4;

void setup() {
  RemoteXY_Init();
  Serial.begin(9600);


  
  while (WiFi.softAPgetStationNum()== 0) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
    Serial.println(WiFi.status());
  }
  Serial.println("Connected to WiFi");
   pinMode(2,OUTPUT);pinMode(3,OUTPUT);pinMode(4,OUTPUT);pinMode(5,OUTPUT);
   pinMode (PIN_SWITCH_1, OUTPUT);
  channel_1.attach(2);
  channel_2.attach(3);
  channel_3.attach(4);
  channel_4.attach(5);
}


void loop() {
    input_ROLL = 1500;
    input_PITCH = 1500;
    input_THROTTLE = 1000;
    input_YAW = 1500;
  RemoteXY_Handler();
  
    int status =WiFi.softAPgetStationNum();;

   int arm=RemoteXY.switch_1;
 // digitalWrite(PIN_SWITCH_1, (RemoteXY.switch_1 == 0) ? LOW : HIGH);
  // yield();
  if ((status==1)&&(arm==1))
  {
  input_ROLL = map(RemoteXY.joystick_2_x, -100, 100, 1200, 2000);
  input_PITCH = map(RemoteXY.joystick_2_y, -100, 100, 1000, 2000);
  input_THROTTLE = map(RemoteXY.joystick_1_y, -100, 100, 1200, 2000);
  input_YAW = map(RemoteXY.joystick_1_x, -100, 100, 1200, 1800);

  channel_1.writeMicroseconds(input_ROLL);
  //yield();
  channel_2.writeMicroseconds(input_PITCH);
  // yield();
  channel_3.writeMicroseconds(input_THROTTLE);
  //yield();
  channel_4.writeMicroseconds(input_YAW);

  Serial.print(channel_1.readMicroseconds());
  Serial.print(" ");
  Serial.print(channel_2.readMicroseconds());
  Serial.print(" ");
  Serial.print(channel_3.readMicroseconds());
  Serial.print(" ");
  Serial.print(channel_4.readMicroseconds());
  Serial.println();
  ///yield();
  }

  else
  {
  channel_1.writeMicroseconds(0);
  //yield();
  channel_2.writeMicroseconds(0);
  // yield();
  channel_3.writeMicroseconds(0);
  //yield();
  channel_4.writeMicroseconds(0);

  Serial.print(channel_1.readMicroseconds());
  Serial.print(" ");
  Serial.print(channel_2.readMicroseconds());
  Serial.print(" ");
  Serial.print(channel_3.readMicroseconds());
  Serial.print(" ");
  Serial.print(channel_4.readMicroseconds());
  Serial.println();
  }
  // Serial.print(channel_1.readMicroseconds());
  // Serial.print(" ");
  // Serial.print(channel_2.readMicroseconds());
  // Serial.print(" ");
  // Serial.print(channel_3.readMicroseconds());
  // Serial.print(" ");
  // Serial.print(channel_4.readMicroseconds());
  // Serial.println();
  Serial.println(status);
  

  //  analogWrite(8,input_ROLL);
  //  analogWrite(9,input_PITCH);
  //  analogWrite(10,input_THROTTLE);
  //  analogWrite(11,input_YAW);
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay()
}