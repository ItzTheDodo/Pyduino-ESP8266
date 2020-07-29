/* Pyduino ESP8266 */

/* Written by: ItzTheDodo
 * Credits to: Junicchi
            *  https://github.com/KebabLord/esp_to_python
 * Pyduino Arduino Code */


#include "ESP_MICRO.h"


void setup() {
  Serial.begin(9600);
  start("-Enter Username-", "-Enter Password-");
}

void loop() {
  waitUntilNewReq();

  if (getPath().indexOf("/High") > 0){
    int a = getPath().indexOf(":");
    String Cpin = getPath().substring(a + 1);
    long pin = Cpin.toInt();
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  if (getPath().indexOf("/Low") > 0){
    int a = getPath().indexOf(":");
    String Cpin = getPath().substring(a + 1);
    long pin = Cpin.toInt();
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }
  if (getPath().indexOf("/out") > 0){
    int a = getPath().indexOf(":");
    String Cpin = getPath().substring(a + 1);
    long pin = Cpin.toInt();
    pinMode(pin, OUTPUT);
  }
  if (getPath().indexOf("/out") > 0){
    int a = getPath().indexOf(":");
    String Cpin = getPath().substring(a + 1);
    long pin = Cpin.toInt();
    pinMode(pin, INPUT);
  }

}
