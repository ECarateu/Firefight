#include "Buzzer.h"

Buzzer::Buzzer(int p){
    pinMode(p,OUTPUT);
    pino=p;
}

void Buzzer::acionar(){
     digitalWrite(pino, HIGH);
}

void Buzzer::desligar(){
     digitalWrite(pino, LOW);
}

bool Buzzer::status(){
    return digitalRead(pino);
}
