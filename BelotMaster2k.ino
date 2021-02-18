// Bela Master 2000 V0.5
// 02.12.2020.

// #include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int SWITCH = 9;
const int RGB1 = 3;
const int RGB2 = 5;
const int RGB3 = 6;
int TURN = 0;

const byte ROWS = 4; // Four rows
const byte COLS = 1; // Three columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'A'},
  {'B'},
  {'C'},
  {'D'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 9, 8, 7, 4 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 2 }; 

// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

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
  Serial.begin(9600);
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
  
  char key = kpd.getKey();
  if(key) {
  }
  switch (key)
  {
    case 'A':
      lcd.setCursor(0,1);
      lcd.print("ADUT JE: BUNDEVA");
      break;
    case 'B':
      lcd.setCursor(0,1);
      lcd.print("ADUT JE:  CRVENA");
      break;
    case 'C':
      lcd.setCursor(0,1);
      lcd.print("ADUT JE:  ZELENA");
      break;
    case 'D':
      lcd.setCursor(0,1);
      lcd.print("ADUT JE:  ZIROVA");
      break;
    default:
        Serial.println(key);
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
