#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Keypad.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//int sortie = 2;
int entree = 5;
int appuie=LOW;
int enCours=0;

void setup() {
  //Serial.begin(9600);
  //randomSeed(analogRead(0));

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.display();
  delay(2000);
  
  display.clearDisplay();

  //pinMode(sortie,OUTPUT);
  pinMode(entree,INPUT);
  //digitalWrite(sortie,HIGH);
}

void loop() {
  appuie=digitalRead(entree);
  
  if(appuie==HIGH && enCours==0){
    enCours=enCours+1;
    TP1();
    //Serial.print("coucou");
    delay(500);
  }
  else if(appuie==HIGH && enCours==1){
    enCours=enCours-1;
    logoTP1();
    //Serial.print(appuie/4);
    //Serial.print("ah");
    delay(500);
  } 
  //Serial.print("ah");
  //delay(1000);
}

void TP1()
{
  display.clearDisplay();

  display.setCursor(28,9);
  display.setTextSize(1.7,2);
  display.setTextColor(SSD1306_WHITE);
  display.println(F("TantePanique"));

  display.display();
}

void logoTP1()
{
    display.clearDisplay();

    display.drawChar(55,9,'T',SSD1306_WHITE,1,2);
    display.drawChar(66,9,'P',SSD1306_WHITE,1,2);
    display.display();
}
