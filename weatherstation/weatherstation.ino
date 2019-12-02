#include <Adafruit_BMP280.h>
#include <dht.h>
#include <LiquidCrystal.h>

/*
 * EGR 124 Final Proj: 
 * Weather Station Code
 * 
 * Written By: Cody Hale, Julio Murillo, 
 * Aaron Huffman
 * 
 */


// Instantiates our LCD, DHT11 and BMP 280 modules
LiquidCrystal lcd(12,11,5,4,3,2);
dht DHT;
Adafruit_BMP280 bme;

// Sets all pin info for modules
const int button = 8;
const int DHT11_PIN = 7;

int displayState = 0;

int buttonState = 0;



void setup() {
  /*
   * Perfoms setup of Serial Stream / LCD / Pin Modes
   */

  Serial.begin(9600);
  lcd.begin(16,2);
  
  pinMode(button, INPUT);


  /*
   * Conditional statement that stops program if 
   * BMP 280 does not successfully get created
   */
  if(!bme.begin()){
    Serial.println("BMP280 not found");
    while(1);
  }
}


void rotateDisplay(){
  /*
   *  Sets the LCD to a periodicly rotating display
   *  that changes on 3 second intervals
   */
  int chk = DHT.read11(DHT11_PIN);
  for(int i = 0; i < 3; i++){
    lcd.clear();
    lcd.setCursor(0,0);
    
    switch(i){
      case 0:

      // Case 0 displays Temp (in F)
      
        lcd.print("Temp: ");
        lcd.print(round(DHT.temperature));
        lcd.print((char)223);
        lcd.print("C"); 
        delay(3000);
        break;
      case 1:
      
      // Case 1 displays Humidty (in %)
        
        lcd.print("Humidity: ");
        lcd.print(round(DHT.humidity));
        lcd.print("%");
        delay(3000);
        break;
      case 2:

      // Case 2 displays Barometric Pressure (in kPa)
        
        lcd.print("P: ");
        lcd.print(round(bme.readPressure()/100)/10);
        lcd.print("kPa");
        delay(3000);
        break;
    }
  }
  
}

void staticDisplay(){
        int chk = DHT.read11(DHT11_PIN);
        
        lcd.clear();
        lcd.setCursor(0,0);
        
        
        lcd.print("T: ");
        lcd.print(round(DHT.temperature));
        lcd.print((char)223);
        lcd.print("C"); 
        
        lcd.setCursor(0,1);
        lcd.print("H: ");
        lcd.print(round(DHT.humidity));
        lcd.print("%");

        lcd.setCursor(8,0);
        lcd.print("P: ");
        lcd.print(round(bme.readPressure()/100)/10);
        lcd.setCursor(9,1);
        lcd.print("kPa");

        delay(1000);
}



void loop() {

  /*
   * Runs on a periodically (1sec basis)
   */
  buttonState = digitalRead(button);

  if(buttonState == HIGH){
    
    displayState++;

    if(displayState>3){
      lcd.clear();
      displayState = 1;
    }
  }
  
  switch(displayState){
      case 1:
        rotateDisplay();
        break;
      case 2:
        staticDisplay();
        break;
      case 3: 
        lcd.clear();
        break;    
   }
  
  delay(1000);          
}
