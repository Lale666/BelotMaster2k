// Bela Master 2000 V0.4
// 18.11.2020.

// #include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int SWITCH = 9;
const int RGB1 = 3;
const int RGB2 = 5;
const int RGB3 = 6;
int TURN = 0;

void setup() {
  pinMode (RGB1,OUTPUT); // blue
  pinMode (RGB2,OUTPUT); // purple
  pinMode (RGB3,OUTPUT); // green
  pinMode (SWITCH,INPUT_PULLUP);
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("* LALE  MIJESA *");
  lcd.setCursor(1,1);
  lcd.print("bela master 2k");
  setColor(255,0,0);
}

void loop() {
  int ValueSW = digitalRead(SWITCH);
  if(ValueSW) {
  }
  else
  {
    TURN++;
    if(TURN==1) {
      lcd.setCursor(0,0);
      lcd.print("* KRAJA MIJESA *");
      setColor(0,255,0);
      delay(666);
    }
    if(TURN==2) {
      lcd.setCursor(0,0);
      lcd.print("* GELAS MIJESA *");
      setColor(0,0,255);
      delay(666);
    }
    if(TURN==3) {
      lcd.setCursor(0,0);
      lcd.print("* FAKI  MIJESA *");
      setColor(255,0,255);
      delay(666);
    }
    if(TURN==4) {
      TURN = 0;
      lcd.setCursor(0,0);
      lcd.print("* LALE  MIJESA *");
      setColor(255,0,0);
      delay(666);
    }
  }
}

void setColor(int red, int green, int blue) {
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(RGB1, red);
  analogWrite(RGB2, green);
  analogWrite(RGB3, blue);  
}
