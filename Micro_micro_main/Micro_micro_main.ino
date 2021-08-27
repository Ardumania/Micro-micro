/*********************************************************************
  This sketch is a demostration of use for the autonomous
  Arduino Micro with Nokia 5110 screen and lipo batterie.

  All the libraries used were developed by Adafruit

  Programed by Josemanu
      @Ardumania_JManu

  Version 0.5 25/8/2021

*********************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>


// Software SPI (slower updates, more flexible pin options):
// Adafruit_PCD8544(SCLK, DIN, D/C, CS, RST)

// My breakout board:
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
// digital pin 9 (with PWM) is used for backlitgh,
// use values between 0 and 168 (3.3v)

// pins 10, 11 and 12 are used as digital input/output
// analog pins A1, A2 and A3 are used as inputs, they can
// be use as digital input/output digital pin numbered
// 15, 16 and 17

// In this example all the pins are use as inputs, don't
// need to declare them as INPUT with pinMode()

// for this example I will connect a DHT22 sensor on pin 10
#include "DHT.h"
#define DHTPIN 10
#define DHTTYPE DHT22   // DHT 22
DHT dht(DHTPIN, DHTTYPE);

// digital pin 13 is used for push button with INPUYT_PULLUP
int pin = 13;

// analog pin A5 is used for measure batterie level.
// we need some bitmaps to show the batterie level.
static const unsigned char PROGMEM bat_full_bmp[] ={
  B01111111, B11111111,
  B01000000, B00000001,
  B11011101, B11011101,
  B11011101, B11011101,
  B11011101, B11011101,
  B01000000, B00000001,
  B01111111, B11111111
};
static const unsigned char PROGMEM bat_half_bmp[] ={
  B01111111, B11111111,
  B01000000, B00000001,
  B11000001, B11011101,
  B11000001, B11011101,
  B11000001, B11011101,
  B01000000, B00000001,
  B01111111, B11111111
};
static const unsigned char PROGMEM bat_empty_bmp[] ={
  B01111111, B11111111,
  B01000000, B00000001,
  B11000000, B00011101,
  B11000000, B00011101,
  B11000000, B00011101,
  B01000000, B00000001,
  B01111111, B11111111
};
static const unsigned char PROGMEM bat_panic_bmp[] ={
  B01111111, B11111111,
  B01000000, B00000001,
  B11000000, B00000001,
  B11000000, B00000001,
  B11000000, B00000001,
  B01000000, B00000001,
  B01111111, B11111111
};

// these variables are needed for the push button
// connected to pin 13
int lastState = 0;
int actualState;
int counter = 0;
int pinForStateChange = 13; 

// each level is a diferent screen
int level = 0;

void setup()   {

// In this example all the pins are used as inputs, don't
// need to declare them as INPUT
  
  pinMode(pin, INPUT_PULLUP);

  display.begin();    // init done
  dht.begin();

  // turn on backlight
  pinMode(9, OUTPUT);
  analogWrite(9, 120);

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(50);

  display.display(); // show Adafruit logo for 2 seconds
  delay(2000);
}


void loop() {

  // if de push button change its state then the screen
  // changes too
  if(hasChanged(pinForStateChange)){
    level++;
    if (level > 6){
    level = 1;  // haha level 0 only be shown for the first time
    }
  }


  display.clearDisplay();  // clear screen and buffer

  // this function displays the batterie level
  drawBatterieStatus();

//               IMPORTANT
//  the order of the pins are, from left to right:
//        A3, A2, A1, 12, 11 and 10
  
  switch (level){
    case 0:
      // begining function
      presentation();
       break;
    case 1:
      // function for input 10
      showTempAndHumidity();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin 10");
     break;
    case 2:
      // function for input 11
      noThingToSee();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin 11");
      break;
    case 3:
      // function for input 12
      noThingToSee();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin 12");
      break;
      
//               IMPORTANT
//  the order of the pins are, from left to right:
//        A3, A2, A1, 12, 11 and 10  

    case 4:
      // function for input A1
      // in this case a force resistor sensor
      showAnalogRead(A1);
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin A1");
      break;
    case 5:
      // function for input A2
      noThingToSee();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin A2");
     break;
    case 6:
      // function for input A3
      showAnalogRead(A3);
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin A3");
     break;
  }

  display.display(); // show data on screen
}

