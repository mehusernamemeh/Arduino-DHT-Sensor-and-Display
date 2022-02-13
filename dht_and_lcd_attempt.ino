//Circuit setup:
//VSS pin on LCD connect to GND power rail
//VDD pin on LCD connect to + power rail
//V0 pin on LCD connect to 200-1000 ohm resistor then wiper of 10k potentiometer
//Connect other two sides of potentiometer to GND rail and + rail
//RS pin on LCD connect to pin 12 on arduino
//RW pin on LCD connect to GND power rail
//E pin on LCD connect to pin 11 on arduino
//D4 pin on LCD connect to pin 5 on arduino
//D5 pin on LCD connect to pin 4 on arduino
//D6 pin on LCD connect to pin 3 on arduino
//D7 pin on LCD connect to pin 2 on arduino
//A pin on LCD to + power rail
//K pin on LCD to GND power rail
//S on DHT11 connect to pin 8
//middle pin on DHT11 connect to + rail
//right pin on DHT11 connect to GND rail
//5V pin on arduino to + power rail
//GND pin on arduino to - power rail

//Include the libraries for DHT sensor and LCD.

#include <LiquidCrystal.h>
#include "DHT.h"

//Define digital pin used by DHT sensor.

#define DHTPIN 8

//Set pin numbers used by LCD, then initialize those pins. (The const int part may not be necessary if you don't want to name the pins.)

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Define the type of DHT temperature sensor you are using (DHT11).

#define DHTTYPE DHT11

//I think this tells the DHT sensor library which pin DHT is using and the type of DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  
//Initialize the DHT sensor.

dht.begin();

//Initialize the LCD.

lcd.begin(16,2);

//Print an empty Temp and Humidity to the LCD.
lcd.print("Temp:  Humidity:");


}

void loop() {
  
//Wait for two seconds.

delay(2000);

//Set cursor position on LCD.

lcd.setCursor(0,1);

//Take a reading for temperature and humidity from DHT11.

float h = dht.readHumidity();
float t = dht.readTemperature();
float f = dht.readTemperature(true);

//If there is an error, display error and return to the delay.

if (isnan(h) || isnan(t) || isnan(f)) {
    lcd.print("ERROR");
    return;
}

//Print out the temperature and humidity readings on the lcd in two different positions.

lcd.print(f);
lcd.setCursor(7,1);
lcd.print(h);
    
}
