//#include <DHT.h>
#include <LiquidCrystal.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bme;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//DHT DHT;
//#define DHT11_PIN 7

void setup()
{  
bme.begin();
lcd.begin(16, 2);
}
void loop()
{  
//int temp = DHT.temperature;
//int farh = (temp * 1.8) + 32;
//int chk = DHT.read11(DHT11_PIN);  
//lcd.setCursor(0,0);  
//lcd.print("Temp: ");  
//lcd.print(temp);
//lcd.print((char)223); 
//lcd.print("C");  
//lcd.setCursor(6,1);
//lcd.print(farh);
//lcd.print((char)223);
//lcd.print("F");
//delay(2000);
//lcd.noDisplay();
//lcd.clear(); 
//lcd.setCursor(0,0);  
//lcd.print("Humidity: ");  
//lcd.print(DHT.humidity);  
//lcd.print("%");  
//delay(500);
//lcd.display();
//delay(2000);
lcd.clear();
lcd.noDisplay();
delay(500);
lcd.print("Pressure: 1 ATM");
lcd.display();
delay(2000);
lcd.clear();

}

