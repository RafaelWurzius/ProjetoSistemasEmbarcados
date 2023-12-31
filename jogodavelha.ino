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
  myServo1.attach(3);   // attaches the servo on pin 9 to the servo object
  myServo2.attach(10);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);   // open a serial connection to your computer
}


void desenhaJogo() {

/*
ANOTAÇÕES

  servo1 -> de cima  -> X -
  servo2 -> de baixo -> Y |

  TODO LIST
  X  Desenhar o jogo
  X  Desenhar X e O
  X  Salvar as posições de cda quadrante(9)
     Montar os botões
     Quando apertar, desenhar no devido quadrante
     Se ganhar riscar a trilha 3 vezes
     Gravar funcionando 
     Montar o desenho do circuito
    
  
*/



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


void desenhaX(int x, int y) {

  int tam = 30;

  myServo1.write(x);
  myServo2.write(y);

  delay(100);

  int i = 0;
  for (i = 0; i <= tam; i++) {
    myServo1.write(x + i);
    myServo2.write(y + i);
    delay(15);
  }

  delay(500);

  myServo2.write(y);

  delay(500);

  for (i = tam; i >= 0; i--) {
    myServo2.write(y + (tam - i));
    myServo1.write(x + i);

    delay(15);
  }

  delay(500);

  myServo1.write(x);
  myServo2.write(y);
  delay(500);
}

void desenhaO(int x, int y) {
  int xAtual = y;
  int yAtual = x;
  int tam = 12;
  int i = 0;
  myServo1.write(y);
  myServo2.write(x);
  delay(100);

  // _
  myServo2.write(xAtual + tam);
  xAtual += tam;

  delay(100);
  // \                                                                                                                                       .
  for (i = 0; i <= tam; i++) {
    myServo1.write(yAtual + i);
    myServo2.write(xAtual + i);

    delay(10);
  }
  yAtual += i;
  xAtual += i;

  // |
  myServo1.write(yAtual + tam);
  yAtual += tam;
  delay(100);

  // /.
  for (i = 0; i <= tam; i++) {
    myServo1.write(yAtual + i);
    myServo2.write(xAtual - i);

    delay(10);
  }
  xAtual -= i;
  yAtual += i;

  // -
  myServo2.write(xAtual - tam);
  xAtual -= tam;
  delay(100);

  // \                                                                                                                                  .
  for (i = 0; i <= tam; i++) {
    myServo1.write(yAtual - i);
    myServo2.write(xAtual - i);

    delay(10);
  }
  xAtual -= i;
  yAtual -= i;

  // |
  myServo1.write(yAtual - tam);
  delay(100);
  yAtual -= tam;

  // /
  for (i = 0; i <= tam; i++) {
    myServo1.write(yAtual - i);
    myServo2.write(xAtual + i);

    delay(10);
  }
  xAtual += i;
  yAtual -= i;
}

void ajusta() {
  myServo1.write(180);
  myServo2.write(180);
}

void loop() {
  if (primeiraVez) {
    desenhaJogo();

    //         (Y  ,  X)
    // desenhaX(15, 140);  // quadrante 7
    // desenhaX(75, 140);  // quadrante 4
    // desenhaX(135, 140); // quadrante 1

    // desenhaX(15, 75);  // quadrante 8
    // desenhaX(75, 75);  // quadrante 5
    // desenhaX(135, 75); // quadrante 2

    // desenhaX(15, 15);   // quadrante 9
    // desenhaX(75, 15);   // quadrante 6
    // desenhaX(135, 15);  // quadrante 3
    //  ---
    desenhaO(15, 140);  // quadrante 7
    desenhaO(75, 140);  // quadrante 4
    desenhaO(135, 140); // quadrante 1

    desenhaO(15, 75);  // quadrante 8
    desenhaO(75, 75);  // quadrante 5
    desenhaO(135, 75); // quadrante 2

    desenhaO(15, 15);   // quadrante 9
    desenhaO(75, 15);   // quadrante 6
    desenhaO(135, 15);  // quadrante 3

    // ajusta();
    primeiraVez = false;
  }
}