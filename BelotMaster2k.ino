// Bela Master 2000 V0.3
// 18.11.2020.

// #include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int SWITCH = 9;
int TURN = 0;

void setup() {
  pinMode (SWITCH,INPUT_PULLUP);
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("LALE  MIJESA");
  lcd.setCursor(1,1);
  lcd.print("bela master 2k");
}

void loop() {
int ValueSW = digitalRead(SWITCH);
  if(ValueSW) {
  }
  else
  {
    TURN++;
    if(TURN==1) {
      lcd.setCursor(2,0);
      lcd.print("KRAJA MIJESA");
      delay(666);
    }
    if(TURN==2) {
      lcd.setCursor(2,0);
      lcd.print("GELAS MIJESA");
      delay(666);
    }
    if(TURN==3) {
      lcd.setCursor(2,0);
      lcd.print("FAKI  MIJESA");
      delay(666);
    }
    if(TURN==4) {
      TURN = 0;
      lcd.setCursor(2,0);
      lcd.print("LALE  MIJESA");
      delay(666);
    }
  }
}
