// BELAS 2K (BELot mASter 2k)
// V0.20
// 13.02.2021.
// Changes since V0.10:
// - partial code rewrite
// - changed 16x2 LCD screen with 20x4 one
// - changed analog keypad with IR remote
// - put comments for easier understanding
// - temporarily removed buzzer due to compatibility issues

#define DECODE_NEC 1                // IR remote protocol definition
#define MARK_EXCESS_MICROS 20    // Compensation for the signal forming of different IR receiver modules
#include <IRremote.h>               // Arduino IRremote library 
#define BUTTON_ONE    0x52          // Remote controller HEX codes for appropriate buttons
#define BUTTON_TWO    0x50
#define BUTTON_THREE  0x10
#define BUTTON_FOUR   0x56
#define BUTTON_FIVE   0x54
#define BUTTON_SIX    0x14
#define BUTTON_SEVEN  0x4E
#define BUTTON_EIGHT  0x4C
#define BUTTON_NINE   0xC
#define BUTTON_ZERO   0xF
#define BUTTON_RED    0x46
#define BUTTON_GREEN  0x44
#define BUTTON_YELLOW 0x4
#define BUTTON_BLUE   0x7
#define BUTTON_OK     0x1A
#define BUTTON_LEFT   0x5A
#define BUTTON_RIGHT  0x1B

#include <LiquidCrystal_I2C.h>      // LCD I2C library
LiquidCrystal_I2C lcd(0x27,20,4);   // Define 20x4 LCD screen

const int IR_RECEIVE_PIN = 9;       // IR Receive on pin 9
const int RGB1 = 3;                 // RGB LED 1 on pin 3
const int RGB2 = 5;                 // RGB LED 2 on pin 5
const int RGB3 = 6;                 // RGB LED 3 on pin 6
// const int BUZZER = 11;              // Buzzer on pin 11
const int DELAY = 300;
int TURN = 0;                       // Player´s turn 
int FLASH = 1;                      // LED Flash
int TRUMP = 0;                      // Trump card color
int CHECK1, CHECK2, CHECK3 = 0;     // Checking if the player has been already selected
int CHECK4, CHECK5, CHECK6 = 0;
const char *FIRST, *SECOND, *THIRD, *FOURTH; // Pointers to players
const char *P1 = "FAKI";           // Players´ names
const char *P2 = "GELAS";
const char *P3 = "KRAJA";
const char *P4 = "LALE";
const char *P5 = "SECA";
const char *P6 = "VRAG";

void setup() {
  pinMode (RGB1,OUTPUT);            // Blue color
  pinMode (RGB2,OUTPUT);            // Red color
  pinMode (RGB3,OUTPUT);            // Green color
  lcd.init();                       // LCD screen initialization
  lcd.backlight();                  // LCD backlight turned on
  lcd.clear();                      // LDC screen cleared
  lcd.setCursor(5,0);
  lcd.print("WELCOME TO");          // Printing a welcoming note
  lcd.setCursor(6,1);
  lcd.print("BELAS 2K");
  lcd.setCursor(8,2);
  lcd.print("V0.20");
  lcd.setCursor(3,3);
  lcd.print("M/F SCUM 2021.");
  setColor(0,0,0);                  // Turn the RGB LED off
//  delay(3500);

  lcd.clear();                      // List of players
  lcd.setCursor(1,0);
  lcd.print("REDOSLIJED IGRACA:");
  lcd.setCursor(0,1);
  lcd.print("1) ");
  lcd.print(P1);
  lcd.setCursor(0,2);
  lcd.print("3) ");
  lcd.print(P3);
  lcd.setCursor(0,3);
  lcd.print("5) ");
  lcd.print(P5);
  lcd.setCursor(11,1);
  lcd.print("2) ");
  lcd.print(P2);
  lcd.setCursor(11,2);
  lcd.print("4) ");
  lcd.print(P4);
  lcd.setCursor(11,3);
  lcd.print("6) ");
  lcd.print(P6);
//  delay(4000);

  Serial.begin(115200);                 // start serial communication
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK); // Start the receiver, disable feedback LED


  while(TURN<4) {
      if (IrReceiver.decode()) {
        switch(IrReceiver.decodedIRData.command) {
          case BUTTON_ONE:
            if(CHECK1>0) break;         // check if player 1 has already been selected
            if(TURN==0) FIRST = P1;
            if(TURN==1) SECOND = P1;
            if(TURN==2) THIRD = P1;
            if(TURN==3) FOURTH = P1;
            setColor(255,0,255);
//            tone(BUZZER, 666, 66);
            delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK1++;                   // Player 1 have been selected
            break;
          case BUTTON_TWO:
            if(CHECK2>0) break;         // check if player 2 has already been selected
            if(TURN==0) FIRST = P2;
            if(TURN==1) SECOND = P2;
            if(TURN==2) THIRD = P2;
            if(TURN==3) FOURTH = P2;
            setColor(255,0,255);
//            tone(BUZZER, 666, 66);
            delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK2++;                   // Player 2 have been selected
            break;
          case BUTTON_THREE:
            if(CHECK3>0) break;         // check if player 3 have already been selected
            if(TURN==0) FIRST = P3;
            if(TURN==1) SECOND = P3;
            if(TURN==2) THIRD = P3;
            if(TURN==3) FOURTH = P3;
            setColor(255,0,255);
//            tone(BUZZER, 666, 66);
          delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK3++;                   // Player 3 have been selected
            break;
          case BUTTON_FOUR:
            if(CHECK4>0) break;         // check if player 4 have already been selected
            if(TURN==0) FIRST = P4;
            if(TURN==1) SECOND = P4;
            if(TURN==2) THIRD = P4;
            if(TURN==3) FOURTH = P4;
            setColor(255,0,255);
//            tone(BUZZER, 666, 66);
          delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK4++;                   // Player 4 have been selected
            break;
          case BUTTON_FIVE:
            if(CHECK5>0) break;         // check if player 5 have already been selected
            if(TURN==0) FIRST = P5;
            if(TURN==1) SECOND = P5;
            if(TURN==2) THIRD = P5;
            if(TURN==3) FOURTH = P5;
            setColor(255,0,255);
//            tone(BUZZER, 666, 66);
            delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK5++;                   // Player 1 have been selected
            break;
          case BUTTON_SIX:
            if(CHECK6>0) break;         // check if player 6 have already been selected
            if(TURN==0) FIRST = P6;
            if(TURN==1) SECOND = P6;
            if(TURN==2) THIRD = P6;
            if(TURN==3) FOURTH = P6;
            setColor(255,0,255);
//            tone(BUZZER, 666, 66);
            delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK6++;                   // Player 1 have been selected
            break;
        }       
        IrReceiver.resume();
      }
    }
  TURN = 0;
  ispis(FIRST,SECOND);
  FLASH = 1;
//  IrReceiver.resume();
}

void loop() {
  if (IrReceiver.decode()) {
    switch(IrReceiver.decodedIRData.command) {
      case BUTTON_OK:
        TURN++;
        if(TURN==1) {
//          zvuk1;
          ispis(SECOND,THIRD);
          FLASH = 1;
          }
        if(TURN==2) {
//          zvuk2;
          ispis(THIRD,FOURTH);
          FLASH = 1;
          }
        if(TURN==3) {
//          zvuk3;
          ispis(FOURTH,FIRST);
          FLASH =1;
          }
        if(TURN==4) {
//          zvuk4;
          ispis(FIRST,SECOND);
          FLASH = 1;
          TURN = 0;
          }
          break;
        case BUTTON_RED:
            setColor(255,0,0);
            lcd.setCursor(0,2);
            lcd.print("ADUT JE:  CRVENA");
            FLASH = 0;
//            delay(DELAY);
            break;
          case BUTTON_GREEN:
            setColor(0,255,0);
            lcd.setCursor(0,2);
            lcd.print("ADUT JE:  ZELENA");
            FLASH = 0;
//           delay(DELAY);
            break;
          case BUTTON_YELLOW:
            setColor(255,255,0);
            lcd.setCursor(0,2);
            lcd.print("ADUT JE:   ZIR  ");
            FLASH = 0;
//            delay(DELAY);
            break;
          case BUTTON_BLUE:
            setColor(0,0,255);
            lcd.setCursor(0,2);
            lcd.print("ADUT JE: BUNDEVA");
            FLASH = 0;
            delay(DELAY);
            break;
        }
      lcd.setCursor(0,3);
      lcd.print(TURN);
      lcd.print(IrReceiver.decodedIRData.command);
      IrReceiver.resume();
      }
//  if(FLASH == 1) {
//  setColor(random(0, 255),random(0, 255),random(0, 255));
//  delay(100);
//  }
  lcd.setCursor(12,3);
  lcd.print(TURN);
  lcd.print("PETLJA");
}

void setColor(int red, int green, int blue) {
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  analogWrite(RGB1, red);
  analogWrite(RGB2, green);
  analogWrite(RGB3, blue);
  }

void ispis(const char *SHUFFLES, const char *PLAYS) {
  setColor(0,0,0);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(SHUFFLES);
  lcd.print(" MIJESA");
  lcd.setCursor(0,1);
  lcd.print(PLAYS);
  lcd.print(" IGRA PRVI");
//  delay(50);
}
