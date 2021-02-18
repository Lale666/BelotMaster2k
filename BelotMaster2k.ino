// Bela Master 2000 V0.2
// 13.11.2020.

const int LED1 = 6;
const int LED2 = 7;
const int LED3 = 8;
const int LED4 = 9;
const int SWITCH = 5;
int LED = 6;

void setup() {

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(SWITCH,INPUT_PULLUP);
  digitalWrite(LED,HIGH);
}

void loop() {

  int ValueSW = digitalRead(SWITCH);
  if(ValueSW)
  {
  }
  else
  {
    digitalWrite(LED,LOW);
    LED++;
    if(LED==10)
    {
      LED = 6;
      digitalWrite(LED,HIGH);
    }    
    digitalWrite(LED,HIGH);
    delay(500);
  }
}
