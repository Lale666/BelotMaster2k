// Bela Master 2000 V0.1
// 13.11.2020.

const int LED1 = 6;
const int LED2 = 7;
const int LED3 = 8;
const int LED4 = 9;
const int SWITCH = 5;

void setup() {

  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(SWITCH,INPUT);
  
}

void loop() {

  digitalWrite(LED1,HIGH);
  delay(666);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  delay(666);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  delay(666);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,HIGH);
  delay(666);
  digitalWrite(LED4,LOW);
  delay(666);

}
