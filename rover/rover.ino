//            |-^-|
// MOTOR 1 -> | | | <- MOTOR 2
//            |_|_|

#define MOTORLON 13
#define MOTORLA 11
#define MOTORLB 12

#define MOTORRON 10
#define MOTORRA 9
#define MOTORRB 8

#define ECHO 7
#define TRIG 6

#define rxPin 5
#define txPin 4

#include <SoftwareSerial.h>

SoftwareSerial BTSerial(rxPin,txPin);
int inputValue;
void setup() {
  inputValue = 48;
  pinMode(MOTORLON,OUTPUT);
  pinMode(MOTORLA,OUTPUT);
  pinMode(MOTORLB,OUTPUT);

  pinMode(MOTORRON,OUTPUT);
  pinMode(MOTORRA,OUTPUT);
  pinMode(MOTORRB,OUTPUT);

  pinMode(TRIG, INPUT);
  pinMode(ECHO, OUTPUT);

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  
  Serial.begin(9600); //coms with computer
  BTSerial.begin(9600); //coms with Bluetooth
}

void loop() {
  if (BTSerial.available()){
    inputValue = (BTSerial.read());
    Serial.println(inputValue);
    if(inputValue == 56){
      forward();
    }
    else if(inputValue == 50){
      backward();
    }
    else if(inputValue == 70){
      turn(1);
    }
    else if(inputValue == 69){
      turn(-1);
    }
    else{
      resetMovement();
    }
  }
}


void turn(int multiplier){
  if(multiplier == -1){
    digitalWrite(MOTORLA,HIGH);
    digitalWrite(MOTORLB,LOW);
    
    digitalWrite(MOTORRA,LOW);
    digitalWrite(MOTORRB,HIGH);
    
  }
  else if(multiplier == 1){
    digitalWrite(MOTORLA,LOW);
    digitalWrite(MOTORLB,HIGH);
    
    digitalWrite(MOTORRA,HIGH);
    digitalWrite(MOTORRB,LOW);
  }
  digitalWrite(MOTORLON,HIGH);
  digitalWrite(MOTORRON,HIGH);
}

void forward(){
  digitalWrite(MOTORLA,HIGH);
  digitalWrite(MOTORLB,LOW);

  digitalWrite(MOTORRA,HIGH);
  digitalWrite(MOTORRB,LOW);

  digitalWrite(MOTORLON,HIGH);
  digitalWrite(MOTORRON,HIGH);
}

void backward(){
  digitalWrite(MOTORLA,LOW);
  digitalWrite(MOTORLB,HIGH);

  digitalWrite(MOTORRA,LOW);
  digitalWrite(MOTORRB,HIGH);

  digitalWrite(MOTORLON,HIGH);
  digitalWrite(MOTORRON,HIGH);
}

void resetMovement(){
  digitalWrite(MOTORLON,LOW);
  digitalWrite(MOTORRON,LOW);
}
