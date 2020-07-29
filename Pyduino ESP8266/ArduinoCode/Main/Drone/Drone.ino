/* Pyduino ESP8266 */

/* Written by: ItzTheDodo
 * Credits to: Junicchi
            *  https://github.com/KebabLord/esp_to_python
 * Drone Arduino Code */

 /*
  * Pins --> Use:
  *
  * 8 --> up (high on up) on path "/up"
  * 9 --> down (high on down) on path "/down"
  * 10 --> right (high on right) oSn path "/right"
  * 11 --> left (high on left) on path "/left"
  * 12 --> forward (high on forward) on path "/forward"
  * 13 --> backward (high on backward) on path "/backward"
  * 
  */

#include "ESP_MICRO.h"
#include "TinyGPS.h"
#include <SoftwareSerial.h>

#define up 8
#define down 9
#define right 10
#define left 11
#define forward 12
#define backward 13

int isUp = 0;
int isDown = 0;
int isRight = 0;
int isLeft = 0;
int isForward = 0;
int isBackward = 0;

float lat;
float lon;
SoftwareSerial gpsSerial(4, 5); //RX, TX
TinyGPS gps;

void setup(){
  Serial.begin(9600);
  gpsSerial.begin(9600);
  start("-Enter Username-", "-Enter Password-");

  pinMode(up, OUTPUT);
  pinMode(down, OUTPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(forward, OUTPUT);
  pinMode(backward, OUTPUT);
}

void loop(){
  waitUntilNewReq();

  if (getPath() == "/up"){
    if (isUp == 0){
      isUp = 1;
      digitalWrite(up, HIGH);
    } else {
      isUp = 0;
      digitalWrite(up, LOW);
    }
  }

  if (getPath() == "/down"){
    if (isDown == 0){
      isDown = 1;
      digitalWrite(down, HIGH);
    } else {
      isDown = 0;
      digitalWrite(down, LOW);
    }
  }

  if (getPath() == "/right"){
    if (isRight == 0){
      isRight = 1;
      digitalWrite(right, HIGH);
    } else {
      isRight = 0;
      digitalWrite(right, LOW);
    }
  }

  if (getPath() == "/left"){
    if (isLeft == 0){
      isLeft = 1;
      digitalWrite(left, HIGH);
    } else {
      isLeft = 0;
      digitalWrite(left, LOW);
    }
  }

  if (getPath() == "/forward"){
    if (isForward == 0){
      isForward = 1;
      digitalWrite(forward, HIGH);
    } else {
      isForward = 0;
      digitalWrite(forward, LOW);
    }
  }

  if (getPath() == "/backward"){
    if (isBackward == 0){
      isBackward = 1;
      digitalWrite(backward, HIGH);
    } else {
      isBackward = 0;
      digitalWrite(backward, LOW);
    }
  }

  if (getPath() == "/dist"){
    while(gpsSerial.available()){
      if(gps.encode(gpsSerial.read())){
        gps.f_get_position(&lat, &lon);
      }
    }
    String latitude = String(lat,6);
    String longitude = String(lon,6);
    returnThisStr("\"[" + latitude + ", " + longitude + "]\"");
  }
  
}
