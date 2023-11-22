/*
  Arduino Starter Kit example
  Project 5 - Servo Mood Indicator

  This sketch is written to accompany Project 5 in the Arduino Starter Kit

  Parts required:
  - servo motor
  - 10 kilohm potentiometer
  - two 100 uF electrolytic capacitors

  created 13 Sep 2012
  by Scott Fitzgerald

  https://store.arduino.cc/genuino-starter-kit

  This example code is part of the public domain.
*/

// include the Servo library
#include <Servo.h>

Servo myServo1;  // create a servo object
Servo myServo2;  // create a servo object

int const potPin1 = A0;  // analog pin used to connect the potentiometer
int potVal1;             // variable to read the value from the analog pin
int angle1;              // variable to hold the angle for the servo motor
int const potPin2 = A5;  // analog pin used to connect the potentiometer
int potVal2;             // variable to read the value from the analog pin
int angle2;              // variable to hold the angle for the servo motor
int primeiraVez = true;

void setup() {
  myServo1.attach(9);   // attaches the servo on pin 9 to the servo object
  myServo2.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);   // open a serial connection to your computer

}

// servo1 = em cima
// servo2 = embaixo
void desenhaJogo() {

  // myServo2.write(0);
  // delay(1000);
  // myServo2.write(180);
  // delay(1000);
  // myServo2.write(180);
  // delay(1000);
  // myServo2.write(180);
  // delay(1000);
  
  //Salvar as posições de cda quadrante(9)
  //Desenhar x e O
  //Pegar 9 botões e fazer com que o desenho seja feito no respectivo quadrante ao botão

  myServo1.write(180);
  myServo2.write(60);
  delay(500);

  myServo1.write(0);
  delay(500);

  myServo1.write(60);
  delay(500);

  myServo2.write(0);
  delay(500);
  myServo2.write(180);
  delay(500);

  myServo2.write(120);
  delay(500);

  myServo1.write(0);
  delay(500);

  myServo1.write(180);
  delay(500);

  myServo1.write(120);
  delay(500);

  myServo2.write(180);
  delay(500);

  myServo2.write(0);
  delay(500);
}

void desenhaX() {
  int i;
  int anguloParaX = 50;

  //diagonal
  for(i = 0; i < 50; i++){
    myServo1.write(anguloParaX + i);
    myServo2.write(anguloParaX + i);
    delay(50);
  }

  anguloParaX = (anguloParaX + i + 10);

  for(i = 0; i < 50; i++){
    myServo1.write(anguloParaX - i);
    myServo2.write(anguloParaX - i);
    delay(50);
  }

}

void desenhaO() {
}


void loop() {
  potVal1 = analogRead(potPin1);  // read the value of the potentiometer
  potVal2 = analogRead(potPin2);  // read the value of the potentiometer
  // print out the value to the Serial Monitor
  Serial.print("potVal: ");
  Serial.print(potVal1);

  // scale the numbers from the pot
  angle1 = map(potVal1, 0, 1023, 0, 179);
  angle2 = map(potVal2, 0, 1023, 0, 179);

  // print out the angle for the servo motor
  // Serial.print(", angle: ");
  // Serial.println(angle1);

  // set the servo position
  // myServo1.write(angle1);
  // myServo2.write(angle2);

  // wait for the servo to get there
  delay(15);

  //desenho

  if (primeiraVez) {
    desenhaX();
    primeiraVez = false;
  }
}
