// Bela Master 2000 V0.9
// 21.01.2021.

#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int SWITCH = 9; // prekidac
const int RGB1 = 3;
const int RGB2 = 5;
const int RGB3 = 6;
const int BUZZER = 11;
const int DELAY = 500;
int TURN = 0;
int BLIC = 1;
int BOJA = 0;
int PROVJERAA, PROVJERAB, PROVJERAC, PROVJERAD = 0;
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

  // ispis igraca
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("A ");
  lcd.print(P1);
  lcd.setCursor(9,0);
  lcd.print("B ");
  lcd.print(P2);
  lcd.setCursor(0,1);
  lcd.print("C ");
  lcd.print(P3);
  lcd.setCursor(9,1);
  lcd.print("D ");
  lcd.print(P4);

  
  while (TURN < 4) {

    // biranje redoslijeda
    char key = kpd.getKey();
    if(key) {
    }
    switch (key)
    {
      case 'A':
      if(PROVJERAA>0) break;  // provjera da li je igrac A vec izabran
      if(TURN==0) PRVI = P1;
      if(TURN==1) DRUGI = P1;
      if(TURN==2) TRECI = P1;
      if(TURN==3) CETVRTI = P1;
      setColor(255,0,255);
      tone(BUZZER, 666, 66);
      delay(DELAY);
      setColor(0,0,0);
      TURN++;
      PROVJERAA++;  // igrac A je izabran
      break;
      case 'B':
      if(PROVJERAB>0) break;  // provjera da li je igrac B vec izabran
      if(TURN==0) PRVI = P2;
      if(TURN==1) DRUGI = P2;
      if(TURN==2) TRECI = P2;
      if(TURN==3) CETVRTI = P2;
      setColor(255,0,255);
      tone(BUZZER, 666, 66);
      delay(DELAY);
      setColor(0,0,0);
      TURN++;
      PROVJERAB++;  // igrac B je izabran
      break;
      case 'C':
      if(PROVJERAC>0) break;  // provjera da li je igrac C vec izabran
      if(TURN==0) PRVI = P3;
      if(TURN==1) DRUGI = P3;
      if(TURN==2) TRECI = P3;
      if(TURN==3) CETVRTI = P3;
      setColor(255,0,255);
      tone(BUZZER, 666, 66);
      delay(DELAY);
      setColor(0,0,0);
      TURN++;
      PROVJERAC++;  // igrac C je izabran
      break;
      case 'D':
      if(PROVJERAD>0) break;  // provjera da li je igrac D vec izabran
      if(TURN==0) PRVI = P4;
      if(TURN==1) DRUGI = P4;
      if(TURN==2) TRECI = P4;
      if(TURN==3) CETVRTI = P4;
      setColor(255,0,255);
      tone(BUZZER, 666, 66);
      delay(DELAY);
      setColor(0,0,0);
      TURN++;
      PROVJERAD++;  // igrac D je izabran
      break;
  }
 }
  TURN = 0;
  ispis(PRVI,DRUGI);
  BLIC = 1;
}

void loop() {
  int ValueSW = digitalRead(SWITCH);
  if(ValueSW) {
  }
  else
  {
    TURN++;
    if(TURN==1) {
      zvuk();
//      tone(BUZZER, 415, 66);
      ispis(DRUGI,TRECI);
      BLIC = 1;
    }
    if(TURN==2) {
      zvuk();
//      tone(BUZZER, 415, 66);
      ispis(TRECI,CETVRTI);
      BLIC = 1;
    }
    if(TURN==3) {
      zvuk();
//      tone(BUZZER, 415, 66);
      ispis(CETVRTI,PRVI);
      BLIC = 1;
    }
    if(TURN==4) {
      TURN = 0;
      zvuk();
//      tone(BUZZER, 415, 66);
      ispis(PRVI,DRUGI);
      BLIC = 1;
    }
  }

  // biranje aduta
  char key = kpd.getKey();
  if(key) {
  }
  switch (key)
  {
    case 'A':
      setColor(0,0,255);
      lcd.setCursor(0,0);
      lcd.print("ADUT JE: BUNDEVA");
      BLIC = 0;
      tone(BUZZER, 666, 66);
      delay(DELAY);
      break;
    case 'B':
      setColor(255,0,0);
      lcd.setCursor(0,0);
      lcd.print("ADUT JE:  CRVENA");
      BLIC = 0;
      tone(BUZZER, 666, 66);
      delay(DELAY);
      break;
    case 'C':
      setColor(0,255,0);
      lcd.setCursor(0,0);
      lcd.print("ADUT JE:  ZELENA");
      BLIC = 0;
      tone(BUZZER, 666, 66);
      delay(DELAY);
      break;
    case 'D':
      setColor(255,255,0);
      lcd.setCursor(0,0);
      lcd.print("ADUT JE:   ZIR  ");
      BLIC = 0;
      tone(BUZZER, 666, 66);
      delay(DELAY);
      break;
    default:  // LEDica nasumicno mijenja boje dok se ne odabere adut
//        Serial.println(key);
          if (BLIC==1) {
            setColor(random(0, 255),random(0, 255),random(0, 255));
            delay(200);
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

void ispis(const char *MIJESA, const char *IGRA) {
  setColor(0,0,0);
  lcd.clear();
  lcd.setCursor(16,0);
  lcd.print("* ");
  lcd.print(MIJESA);
  lcd.print(" MIJESA *");
  lcd.setCursor(16,1);
  lcd.print(IGRA);
  lcd.print("  IGRA PRVI");
  delay(150);
  for (int x = 15; x > -1; x--) {
    lcd.scrollDisplayLeft();
    lcd.clear();
    lcd.setCursor(x,0);
    lcd.print("* ");
    lcd.print(MIJESA);
    lcd.print(" MIJESA *");
    lcd.setCursor(x,1);
    lcd.print(IGRA);
    lcd.print(" IGRA PRVI!");
    delay(150);
  }
}

void zvuk() {
  tone(BUZZER, 830);
  delay(250);
  noTone(BUZZER);
  tone(BUZZER, 622);
  delay(250);
  noTone(BUZZER);
  tone(BUZZER, 415);
  delay(250);
  noTone(BUZZER);
  tone(BUZZER, 466);
  delay(250);
  noTone(BUZZER);
}
