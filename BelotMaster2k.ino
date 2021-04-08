// Belot Master 2k
// V0.30
// 01.04.2021.
// Changes since V0.29:
// - new IR remote with new codes (the old one didn´t have all functional keys)
// - simplified the way values are entered
// - other minor QoL improvements

#define DECODE_NEC 1                    // IR remote protocol definition
#define MARK_EXCESS_MICROS 20           // Compensation for the signal forming of different IR receiver modules
#include <IRremote.h>                   // Arduino IRremote library 
#define BUTTON_ONE        0x11          // Remote controller HEX codes for appropriate buttons
#define BUTTON_TWO        0x12
#define BUTTON_THREE      0x13
#define BUTTON_FOUR       0x14
#define BUTTON_FIVE       0x15
#define BUTTON_SIX        0x16
#define BUTTON_SEVEN      0x17
#define BUTTON_EIGHT      0x18
#define BUTTON_NINE       0x19
#define BUTTON_ZERO       0x10
#define BUTTON_RED        0xB
#define BUTTON_GREEN      0x4
#define BUTTON_YELLOW     0x5
#define BUTTON_BLUE       0xC
#define BUTTON_OK         0xE
#define BUTTON_LEFT       0x7
#define BUTTON_RIGHT      0x6
#define BUTTON_UP         0x40
#define BUTTON_DOWN       0x41
#define BUTTON_EXIT       0x50
#define BUTTON_GUIDE      0x43
#define BUTTON_INFO       0x1E
#define BUTTON_CH_PLUS    0x0
#define BUTTON_CH_MINUS   0x1
#define BUTTON_VOL_PLUS   0x2
#define BUTTON_VOL_MINUS  0x3

#include <LiquidCrystal_I2C.h>          // LCD I2C library
LiquidCrystal_I2C lcd(0x27,20,4);       // Define 20x4 LCD screen

#include <UniversalTimer.h>
UniversalTimer FiveSeconds(5000, true); // Five seconds repeating timer

const int IR_RECEIVE_PIN = 9;           // IR Receive on pin 9
const int RGB1 = 3;                     // RGB LED 1 on pin 3
const int RGB2 = 5;                     // RGB LED 2 on pin 5
const int RGB3 = 6;                     // RGB LED 3 on pin 6
// const int BUZZER = 11;              // Buzzer on pin 11
const int DELAY = 150;
int TURN = 0;                           // Player´s turn 
boolean FLASH = true;                   // LED Flash
boolean RESET = false;                  // A flag to reset all the temporary values
// boolean SECURITY = false;               // A flag to prevent accidental pressing of OK key
boolean CHECK1, CHECK2, CHECK3 = false;         // Checking if the player has been already selected
boolean CHECK4, CHECK5, CHECK6 = false;
int HAND1, HAND2 = 0;                   // Values of hand for both teams (straight, 4 of a kind etc)
int TEAM1, TEAM2 = 0;                   // Overall result for both teams
int RESULT1, RESULT2 = 0;               // Current result for both teams
int TRES1, TRES2 = 0;                   // Temporary result for both teams
int TOTAL = 162;                        // Total hand points
const char *FIRST, *SECOND, *THIRD, *FOURTH; // Pointers to players
const char *P1 = "FAKI  ";                // Players´ names
const char *P2 = "GELAS ";
const char *P3 = "KRAJA ";
const char *P4 = "LALE  ";
const char *P5 = "SECA  ";
const char *P6 = "SKRGA ";

void setup() {
  pinMode (RGB1,OUTPUT);                // Blue color
  pinMode (RGB2,OUTPUT);                // Red color
  pinMode (RGB3,OUTPUT);                // Green color
  lcd.init();                           // LCD screen initialization
  lcd.backlight();                      // LCD backlight turned on
  lcd.clear();                          // LDC screen cleared
  lcd.setCursor(5,0);
  lcd.print("WELCOME TO");              // Printing a welcoming note
  lcd.setCursor(2,1);
  lcd.print("BELOT MASTER 2k");
  lcd.setCursor(7,2);
  lcd.print("V 0.30");
  lcd.setCursor(3,3);
  lcd.print("M/F SCUM 2021.");
  setColor(0,0,0);                      // Turn the RGB LED off
  delay(4000);

  lcd.clear();                          // Printing the list of players
  lcd.setCursor(1,0);
  lcd.print("REDOSLIJED IGRACA:");
  lcd.setCursor(0,1);
  lcd.print("1) ");
  lcd.print(P1);
  lcd.setCursor(0,2);
  lcd.print("2) ");
  lcd.print(P2);
  lcd.setCursor(0,3);
  lcd.print("3) ");
  lcd.print(P3);
  lcd.setCursor(11,1);
  lcd.print("4) ");
  lcd.print(P4);
  lcd.setCursor(11,2);
  lcd.print("5) ");
  lcd.print(P5);
  lcd.setCursor(11,3);
  lcd.print("6) ");
  lcd.print(P6);

  Serial.begin(115200);                     // start serial communication
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK); // Start the receiver, disable feedback LED


  while(TURN<4) {
      if (IrReceiver.decode()) {
        switch(IrReceiver.decodedIRData.command) {
          case BUTTON_ONE:
            if(CHECK1==true) break;         // check if player 1 has already been selected
            switch(TURN) {
              case 0: FIRST = P1; break;
              case 1: SECOND = P1; break;
              case 2: THIRD = P1; break;
              case 3: FOURTH = P1; break;
            }
            setColor(255,255,255);
//            tone(BUZZER, 666, 66);
            delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK1=true;                    // Player 1 have been selected
            lcd.setCursor(0,1);
            lcd.print("X");
            break;
          case BUTTON_TWO:
            if(CHECK2==true) break;         // check if player 2 has already been selected
            switch(TURN) {
              case 0: FIRST = P2; break;
              case 1: SECOND = P2; break;
              case 2: THIRD = P2; break;
              case 3: FOURTH = P2; break;
            }
            setColor(255,255,255);
//            tone(BUZZER, 666, 66);
            delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK2=true;                    // Player 2 have been selected
            lcd.setCursor(0,2);
            lcd.print("X");
            break;
          case BUTTON_THREE:
            if(CHECK3==true) break;         // check if player 3 have already been selected
            switch(TURN) {
              case 0: FIRST = P3; break;
              case 1: SECOND = P3; break;
              case 2: THIRD = P3; break;
              case 3: FOURTH = P3; break;
            }
            setColor(255,255,255);
//            tone(BUZZER, 666, 66);
          delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK3=true;                   // Player 3 have been selected
            lcd.setCursor(0,3);
            lcd.print("X");
            break;
          case BUTTON_FOUR:
            if(CHECK4==true) break;        // check if player 4 have already been selected
            switch(TURN) {
              case 0: FIRST = P4; break;
              case 1: SECOND = P4; break;
              case 2: THIRD = P4; break;
              case 3: FOURTH = P4; break;
            }
            setColor(255,255,255);
//            tone(BUZZER, 666, 66);
          delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK4=true;                     // Player 4 have been selected
            lcd.setCursor(11,1);
            lcd.print("X");
            break;
          case BUTTON_FIVE:
            if(CHECK5==true) break;         // check if player 5 have already been selected
            switch(TURN) {
              case 0: FIRST = P5; break;
              case 1: SECOND = P5; break;
              case 2: THIRD = P5; break;
              case 3: FOURTH = P5; break;
            }
            setColor(255,255,255);
//            tone(BUZZER, 666, 66);
            delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK5=true;                    // Player 1 have been selected
            lcd.setCursor(11,2);
            lcd.print("X");
            break;
          case BUTTON_SIX:
            if(CHECK6==true) break;         // check if player 6 have already been selected
            switch(TURN) {
              case 0: FIRST = P6; break;
              case 1: SECOND = P6; break;
              case 2: THIRD = P6; break;
              case 3: FOURTH = P6; break;
            }
            setColor(255,255,255);
//            tone(BUZZER, 666, 66);
            delay(DELAY);
            setColor(0,0,0);
            TURN++;
            CHECK6=true;                    // Player 1 have been selected
            lcd.setCursor(11,3);
            lcd.print("X");
            break;
        }       
        IrReceiver.resume();
      }
    }
  TURN = 0;
  ispis(FIRST,SECOND,TEAM1,TEAM2,RESULT1,RESULT2);
  FLASH = true;
  FiveSeconds.start();
//  IrReceiver.resume();
}

void loop() {
  if (IrReceiver.decode()) {
    switch(IrReceiver.decodedIRData.command) {
      case BUTTON_OK:
//        if(SECURITY=true) break;
        TURN++;
        switch(TURN) {
          case 1: ispis(SECOND,THIRD,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 2: ispis(THIRD,FOURTH,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 3: ispis(FOURTH,FIRST,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 4: ispis(FIRST,SECOND,TEAM1,TEAM2,RESULT1,RESULT2); TURN = 0; break;
        }
        FLASH = true;
        RESET = true;
        delay(DELAY);
        break;
      case BUTTON_RED:
        setColor(255,0,0);
        lcd.setCursor(12,3);
        lcd.print("CRVENA ");
        FLASH = false;
        delay(DELAY);
        break;
      case BUTTON_GREEN:
        setColor(0,255,0);
        lcd.setCursor(12,3);
        lcd.print("ZELENA ");
        FLASH = false;
        delay(DELAY);
        break;
      case BUTTON_YELLOW:
        setColor(255,255,0);
        lcd.setCursor(12,3);
        lcd.print("ZIR    ");
        FLASH = false;
        delay(DELAY);
        break;
      case BUTTON_BLUE:
        setColor(0,0,255);
        lcd.setCursor(12,3);
        lcd.print("BUNDEVA");
        FLASH = false;
        delay(DELAY);
        break;
      case BUTTON_GUIDE:
        HAND1 = upisz(12,1,HAND1);
        TOTAL = 162 + HAND1 + HAND2;
//        SECURITY = true;
        lcd.setCursor(12,1);
        lcd.print("   ");
        lcd.setCursor(12,1);
        lcd.print(HAND1);
        lcd.setCursor(17,2);
        lcd.print(TOTAL);
        break;
      case BUTTON_INFO:
        HAND2 = upisz(16,1,HAND2);
        TOTAL = 162 + HAND1 + HAND2;
//        SECURITY = true;
        lcd.setCursor(16,1);
        lcd.print("   ");
        lcd.setCursor(16,1);
        lcd.print(HAND2);
        lcd.setCursor(17,2);
        lcd.print(TOTAL);
        break;
      case BUTTON_LEFT:
        TRES1 = upis(0,1,TOTAL);
        if(TRES1 != 1) {
          TRES2 = TOTAL - TRES1;
          RESULT1 = RESULT1 + TRES1;
          RESULT2 = RESULT2 + TRES2;
//          SECURITY = false;
        }
        lcd.setCursor(0,1);
        lcd.print("   ");
        lcd.setCursor(0,1);
        lcd.print(RESULT1);
        lcd.setCursor(6,1);
        lcd.print(RESULT2);
        if(TRES1 == 1) {
          TRES1 = 0;
          break;
        }
        TURN++;
        TOTAL = 162;
        switch(TURN) {
          case 1: ispis(SECOND,THIRD,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 2: ispis(THIRD,FOURTH,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 3: ispis(FOURTH,FIRST,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 4: ispis(FIRST,SECOND,TEAM1,TEAM2,RESULT1,RESULT2); TURN = 0; break;
        }
        FLASH = true;
        RESET = true;
        delay(DELAY);
        break;
      case BUTTON_RIGHT:
        TRES2 = upis(6,1,TOTAL);
        if(TRES2 != 1) {
          TRES1 = TOTAL - TRES2;
          RESULT2 = RESULT2 + TRES2;
          RESULT1 = RESULT1 + TRES1;
//          SECURITY = false;
        }
        lcd.setCursor(0,1);
        lcd.print(RESULT1);
        lcd.setCursor(6,1);
        lcd.print("   ");
        lcd.setCursor(6,1);
        lcd.print(RESULT2);
        if(TRES2 == 1) {
          TRES2 = 0;
          break;
        }
        TURN++;
        TOTAL = 162;
        switch(TURN) {
          case 1: ispis(SECOND,THIRD,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 2: ispis(THIRD,FOURTH,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 3: ispis(FOURTH,FIRST,TEAM1,TEAM2,RESULT1,RESULT2); break;
          case 4: ispis(FIRST,SECOND,TEAM1,TEAM2,RESULT1,RESULT2); TURN = 0; break;
        }
        FLASH = true;
        RESET = true;
        delay(DELAY);
        break;
//      case BUTTON_VOL_PLUS:
//        TEAM1++;
//        lcd.setCursor(3,0);
//        lcd.print(TEAM1);
//        delay(DELAY);
//        break;
//      case BUTTON_VOL_MINUS:
//        TEAM1--;
//        if(TEAM1<0) TEAM1 = 0;
//        lcd.setCursor(3,0);
//      lcd.print("  ");
//        lcd.setCursor(3,0);
//        lcd.print(TEAM1);
//        delay(DELAY);
//        break;
//      case BUTTON_CH_PLUS:
//        TEAM2++;
//        lcd.setCursor(9,0);
//        lcd.print(TEAM2);
//        delay(DELAY);
//        break;
//      case BUTTON_CH_MINUS:
//        TEAM2--;
//        if(TEAM2<2) TEAM2 = 0;
//       lcd.setCursor(9,0);
//       lcd.print("  ");
//        lcd.setCursor(9,0);
//        lcd.print(TEAM2);
//        delay(DELAY);
//        break;
      }
  IrReceiver.resume();
  }
if(FiveSeconds.check() & FLASH == true) {
  setColor(255,255,255);
  delay(DELAY);
  setColor(0,0,0);
  }
if(RESULT1>1000 & RESULT1>RESULT2) {
  TEAM1++;
  pobjeda(RESULT1, RESULT2, true);
  RESULT1 = 0;
  RESULT2 = 0;
  RESET = true;
  }
if(RESULT1>1000 & RESULT1<RESULT2) {
  TEAM2++;
  pobjeda(RESULT1, RESULT2, false);
  RESULT1 = 0;
  RESULT2 = 0;
  RESET = true;
  }
if(RESULT2>1000 & RESULT2>RESULT1) {
  TEAM2++;
  pobjeda(RESULT1, RESULT2, false);
  RESULT1 = 0;
  RESULT2 = 0;
  RESET = true;
  }
if(RESULT2>1000 & RESULT2<RESULT1) {
  TEAM1++;
  pobjeda(RESULT1, RESULT2, true);
  RESULT1 = 0;
  RESULT2 = 0;
  RESET = true;
  }
if(RESET==true) {
  TOTAL = 162;
  TRES1 = 0;
  TRES2 = 0;
  HAND1 = 0;
  HAND2 = 0;
//  SECURITY = false;
  RESET = false;
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

void pobjeda(int RES1, int RES2, boolean TIM) {       // winning screen function
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("REZULTAT  JE");
  lcd.setCursor(5,1);
  lcd.print(RES1);
  lcd.print(" : ");
  lcd.print(RES2);
  lcd.setCursor(2,2);
  lcd.print("POBJEDA TIMA: ");
  if(TIM == true) lcd.print("MI");
  if(TIM == false) lcd.print("VI");
  lcd.setCursor(0,3);
  lcd.print("-> OK za nastavak <-");
}

void ispis(const char *SHUFFLES, const char *PLAYS, int TEAM01, int TEAM02, int RES01, int RES02) {
  setColor(0,0,0);
  lcd.clear();
  lcd.home();
  lcd.print("MI ");
  lcd.print(TEAM01);
  lcd.setCursor(6,0);
  lcd.print("VI ");
  lcd.print(TEAM02);
  lcd.setCursor(11,0);
  lcd.print("|");
  lcd.setCursor(13,0);
  lcd.print("zvanja");
  lcd.setCursor(0,1);
  lcd.print(RES01);
  lcd.setCursor(6,1);
  lcd.print(RES02);
  lcd.setCursor(11,1);
  lcd.print("|");
  lcd.setCursor(0,2);
  lcd.print("prvi ");
  lcd.print(PLAYS);
  lcd.setCursor(11,2);
  lcd.print("|");
  lcd.print("igra ");
  lcd.print(TOTAL);
  lcd.setCursor(0,3);
  lcd.print("muss ");
  lcd.print(SHUFFLES);
  lcd.setCursor(11,3);
  lcd.print("|");
  lcd.setCursor(12,3);
  lcd.print("adut ?");
}

int upisz(int X, int Y, int Z) {
  int RESULT = Z;
  boolean TRIGGER = false;
  lcd.setCursor(X,Y);
  lcd.blink();
  lcd.print(Z);
  while(TRIGGER != true) {
    if (IrReceiver.decode()) {
      switch(IrReceiver.decodedIRData.command) {
        case BUTTON_UP:
          if(RESULT == 820) break;
          RESULT = RESULT + 10;
          lcd.setCursor(X,Y);
          lcd.print("   ");
          lcd.setCursor(X,Y);
          lcd.print(RESULT);
          delay(DELAY/2);
          break;
        case BUTTON_DOWN:
          if(RESULT == 0) break;
          RESULT = RESULT - 10;
          lcd.setCursor(X,Y);
          lcd.print("   ");
          lcd.setCursor(X,Y);
          lcd.print(RESULT);
          delay(DELAY/2);
          break;
        case BUTTON_EXIT:
          TRIGGER = true;
          RESULT = Z;
          delay(DELAY);
          break;
        case BUTTON_OK:
          TRIGGER = true;
          delay(DELAY);
          break;
      }
      IrReceiver.resume();
    }
  }
  lcd.noBlink();
  return RESULT;
}

int upis(int X, int Y, int Z) {                            // result input function
  int RESULT = 0;                       // result
  int TOTAL = Z ;
  boolean TRIGGER = false;                
  lcd.setCursor(X,Y);
  lcd.print("   ");
  lcd.setCursor(X,Y);
  lcd.blink();
  lcd.print(RESULT);
  while(TRIGGER != true) {
    if (IrReceiver.decode()) {
      switch(IrReceiver.decodedIRData.command) {
        case BUTTON_UP:
          if((RESULT+10) > TOTAL) break;
          RESULT =  RESULT + 10;
          lcd.setCursor(X,Y);
          lcd.print("   ");
          lcd.setCursor(X,Y);
          lcd.print(RESULT);
          delay(DELAY/2);
          break;
        case BUTTON_DOWN:
          if((RESULT-10) < 0) break;
          RESULT = RESULT - 10;
          lcd.setCursor(X,Y);
          lcd.print("   ");
          lcd.setCursor(X,Y);
          lcd.print(RESULT);
          delay(DELAY/2);
          break;
        case BUTTON_RIGHT:
          if(RESULT >= TOTAL) break;
          RESULT++;
          lcd.setCursor(X,Y);
          lcd.print("   ");
          lcd.setCursor(X,Y);
          lcd.print(RESULT);
          delay(DELAY/2);
          break;
        case BUTTON_LEFT:
          if(RESULT <= 0) break;
          RESULT--;
          lcd.setCursor(X,Y);
          lcd.print("   ");
          lcd.setCursor(X,Y);
          lcd.print(RESULT);
          delay(DELAY/2);
          break;
        case BUTTON_EXIT:
          TRIGGER = true;
          RESULT = 1;
          delay(DELAY);
          break;
        case BUTTON_OK:
          TRIGGER = true;
          delay(DELAY);
          break;
      }
      IrReceiver.resume();
    }
  }
  lcd.noBlink();
  return RESULT;
}
