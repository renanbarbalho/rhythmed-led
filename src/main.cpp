#include <Arduino.h>

/**
 * Author: Renan Barbalho
 * E-mail: renanbarbalho@gmail.com
 * Version: 1.0
 * 
 * This code works in arduino UNO, using the pins:
 * 
 * LED:
 * 
 * RED - PIN (PWN) 11
 * GREEN - PIN (PWN) 10
 * BLUE - PIN (PWN) 9
 * 
 * SOUND SENSOR:
 * 
 * SENSOR - PIN (A) 2
 * 
 * Remember: Between LED and Arduino use a resistor 220 oms or 300 oms
 * 
 * */

int SOUND_SENSOR = 2;

int LED_R = 11;
int LED_G = 10;
int LED_B = 9;

int BRIGHTNESS = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(SOUND_SENSOR, INPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void RGB_color(int red_value, int green_value, int blue_value, int brightness)
{
  analogWrite(LED_R, red_value - brightness);
  analogWrite(LED_G, green_value - brightness);
  analogWrite(LED_B, blue_value - brightness);
}

void rainbow(int brightness)
{
  RGB_color(255, 0, 0, brightness); // Red
  delay(1000);
  RGB_color(0, 255, 0, brightness); // Green
  delay(1000);
  RGB_color(0, 0, 255, brightness); // Blue
  delay(1000);
  RGB_color(255, 255, 125, brightness); // Raspberry
  delay(1000);
  RGB_color(0, 255, 255, brightness); // Cyan
  delay(1000);
  RGB_color(255, 0, 255, brightness); // Magenta
  delay(1000);
  RGB_color(255, 255, 0, brightness); // Yellow
  delay(1000);
  RGB_color(255, 255, 255, brightness); // White
  delay(1000);
}

void loop()
{
  int VL_SOM = analogRead(SOUND_SENSOR);

  Serial.println("VL_SOM: " + VL_SOM);

  BRIGHTNESS = VL_SOM / 2;

  Serial.println("BRIGHTNESS:" + BRIGHTNESS);

  rainbow(BRIGHTNESS);
}