// Bela Master 2000 V0.6
// 09.12.2020.

// #include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int SWITCH = 9;
const int RGB1 = 3;
const int RGB2 = 5;
const int RGB3 = 6;
const int DELAY = 500;
int TURN = 0;
const char *PRVI, *DRUGI, *TRECI, *CETVRTI;
const char *P1 = "FAKI ";
const char *P2 = "GELAS";
const char *P3 = "KRAJA";
const char *P4 = "LALE ";

const byte ROWS = 4; // Four rows
const byte COLS = 1; // Three columns
char keys[ROWS][COLS] = {
  {'A'},
  {'B'},
  {'C'},
  {'D'}
};
byte rowPins[ROWS] = { 9, 8, 7, 4 };
byte colPins[COLS] = { 2 }; 
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  pinMode (RGB1,OUTPUT); // blue
  pinMode (RGB2,OUTPUT); // purple
  pinMode (RGB3,OUTPUT); // green
  pinMode (SWITCH,INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.print("   WELCOME TO   ");
  lcd.setCursor(1,1);
  lcd.print(" THE MACHINE!   ");
  setColor(0,0,0);
  Serial.begin(9600);
  delay(3000);

  lcd.setCursor(0,0);
  lcd.print("A) FAKI B) GELAS");
  lcd.setCursor(0,1);
  lcd.print("C) KRAJA D) LALE");
  
  while (TURN < 4) {
    char key = kpd.getKey();
    if(key) {
    }
    switch (key)
    {
      case 'A':
      if(TURN==0) PRVI = P1;
      if(TURN==1) DRUGI = P1;
      if(TURN==2) TRECI = P1;
      if(TURN==3) CETVRTI = P1;
      setColor(255,0,255);
      delay(DELAY);
      setColor(0,0,0);
      TURN++;
      break;
      case 'B':
      if(TURN==0) PRVI = P2;
      if(TURN==1) DRUGI = P2;
      if(TURN==2) TRECI = P2;
      if(TURN==3) CETVRTI = P2;
      setColor(255,0,255);
      delay(DELAY);
      setColor(0,0,0);
      TURN++;
      break;
      case 'C':
      if(TURN==0) PRVI = P3;
      if(TURN==1) DRUGI = P3;
      if(TURN==2) TRECI = P3;
      if(TURN==3) CETVRTI = P3;
      setColor(255,0,255);
      delay(DELAY);
      setColor(0,0,0);
      TURN++;
      break;
      case 'D':
      if(TURN==0) PRVI = P4;
      if(TURN==1) DRUGI = P4;
      if(TURN==2) TRECI = P4;
      if(TURN==3) CETVRTI = P4;
      setColor(255,0,255);
      delay(DELAY);
      setColor(0,0,0);
      TURN++;
      break;
  }
 }
  TURN = 0;
  ispis(PRVI);
}

void loop() {
  int ValueSW = digitalRead(SWITCH);
  if(ValueSW) {
  }
  else
  {
    TURN++;
    if(TURN==1) {
      ispis(DRUGI);
    }
    if(TURN==2) {
      ispis(TRECI);
    }
    if(TURN==3) {
      ispis(CETVRTI);
    }
    if(TURN==4) {
      TURN = 0;
      ispis(PRVI);
    }
  }
  
  char key = kpd.getKey();
  if(key) {
  }
  switch (key)
  {
    case 'A':
      setColor(0,0,255);
      lcd.setCursor(0,1);
      lcd.print("ADUT JE: BUNDEVA");
      delay(DELAY);
      break;
    case 'B':
      setColor(255,0,0);
      lcd.setCursor(0,1);
      lcd.print("ADUT JE:  CRVENA");
      delay(DELAY);
      break;
    case 'C':
      setColor(0,255,0);
      lcd.setCursor(0,1);
      lcd.print("ADUT JE:  ZELENA");
      delay(DELAY);
      break;
    case 'D':
      setColor(255,255,0);
      lcd.setCursor(0,1);
      lcd.print("ADUT JE:   ZIR  ");
      delay(DELAY);
      break;
//    default:
//        Serial.println(key);
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

void ispis(const char *MIJESA) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("* ");
  lcd.print(MIJESA);
  lcd.print(" MIJESA *");
// lcd.setCursor(0,1);
// lcd.print("* ");
// lcd.print(MUS);
// lcd.print(" JE MUS *");
  delay(DELAY);
}
