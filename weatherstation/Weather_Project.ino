#include "DHT.h"
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE); //initializes dht object

Adafruit_BMP280 bme; //initializes bme object

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  lcd.begin(16,2);
  dht.begin();
  bme.begin();

}

void loop() {
  //delay to allow the sensor to update
  delay(2000);
  //setting up temperature and humidity variables
  int temp = dht.readTemperature();
  int farh = temp * (9/5) + 32;
  int hum = dht.readHumidity();
  int pres = bme.readPressure() / 100;
  //printing process
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(6,1); //alligns standard reading with metric reading
  lcd.print(farh);
  lcd.print((char)223);
  lcd.print("F");
  lcd.display();
  delay(2000);
  lcd.clear();
  lcd.noDisplay();
  lcd.setCursor(0,0);
  lcd.print("Pressure: ");
  lcd.print(pres);
  lcd.print("mb");
  delay(500);
  lcd.display();
  delay(2000);
  lcd.clear();
  lcd.noDisplay();

  
  
  

  
}
