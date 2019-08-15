#include "Motores.h"
int a,b,c,d;
Motores::Motores(int a, int b, int c, int d){
    pinMode(a,OUTPUT);
    pinMode(b,OUTPUT);
    pinMode(c,OUTPUT);
    pinMode(d,OUTPUT);
    
   IN1 = a;
   IN2 = b;
   IN3 = c;
   IN4 = d;
   
}

void Motores::frente(){
  
   //digitalWrite(a, LOW);
   // digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
  
}

void Motores::tras(){
  
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    
}
void Motores::direita(){
     
}
void Motores::esquerda(){
     
}
void Motores::parar(){
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
}
