//servo

#include <Servo.h>

const int pinServo = 10;
int i;
Servo monServo;

//echo1
const int TrigPin1 = 2;
const int EchoPin1 = 3;
float distance1;

const int TrigPin2 = 4;
const int EchoPin2 = 5;
float distance2;

const int TrigPin3 = 6;
const int EchoPin3 = 7;
float distance3;

const int TrigPin4 = 8;
const int EchoPin4 = 9;
float distance4;

float facteur = 0.95;

int valeurDistance_lisse_01;
int prev_valeurDistance_01 = 0;

int valeurDistance_lisse_02;
int prev_valeurDistance_02 = 0;

int valeurDistance_lisse_03;
int prev_valeurDistance_03 = 0;

int valeurDistance_lisse_04;
int prev_valeurDistance_04 = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(57600);

  //servo

  monServo.attach(pinServo);

  //1
  pinMode(TrigPin1, OUTPUT);
  pinMode(EchoPin1, INPUT);
  digitalWrite(TrigPin1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:


  //1

  //sonar1
  digitalWrite(TrigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin1, LOW);

  distance1 = pulseIn(EchoPin1, HIGH) / 58.8;  //echo converti en cm

  valeurDistance_lisse_01 = distance1 * (1.0 - facteur) + (prev_valeurDistance_01 * facteur);
  prev_valeurDistance_01 = valeurDistance_lisse_01;

  //servo

  monServo.write(valeurDistance_lisse_01);


  //2

  //sonar2
  digitalWrite(TrigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin2, LOW);

  distance1 = pulseIn(EchoPin2, HIGH) / 58.8;  //echo converti en cm

  valeurDistance_lisse_02 = distance2 * (1.0 - facteur) + (prev_valeurDistance_02 * facteur);
  prev_valeurDistance_02 = valeurDistance_lisse_02;

  //servo

  monServo.write(valeurDistance_lisse_02);


  //3

  //sonar3
  digitalWrite(TrigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin3, LOW);

  distance1 = pulseIn(EchoPin3, HIGH) / 58.8;  //echo converti en cm

  valeurDistance_lisse_03 = distance3 * (1.0 - facteur) + (prev_valeurDistance_03 * facteur);
  prev_valeurDistance_03 = valeurDistance_lisse_03;

  //servo

  monServo.write(valeurDistance_lisse_03);



  //4

  //sonar1
  digitalWrite(TrigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin4, LOW);

  distance4 = pulseIn(EchoPin4, HIGH) / 58.8;  //echo converti en cm

  valeurDistance_lisse_04 = distance4 * (1.0 - facteur) + (prev_valeurDistance_04 * facteur);
  prev_valeurDistance_04 = valeurDistance_lisse_04;

  //servo

  monServo.write(valeurDistance_lisse_04);




  //print

  Serial.print(" ");
  Serial.print(distance1);  //en cm

  Serial.print(" ");
  Serial.print(valeurDistance_lisse_01);  //en cm

  Serial.print(" ");
  Serial.print(distance2);  //en cm

  Serial.print(" ");
  Serial.print(valeurDistance_lisse_02);  //en cm

  Serial.print(" ");
  Serial.print(distance3);  //en cm

  Serial.print(" ");
  Serial.print(valeurDistance_lisse_03);  //en cm

  Serial.print(" ");
  Serial.print(distance4);  //en cm

  Serial.print(" ");
  Serial.print(valeurDistance_lisse_04);  //en cm


  Serial.println();
}

