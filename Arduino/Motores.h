#ifndef Motores_h
#define Motores_h
#include <Arduino.h>

class Motores{
    private:
        int IN1,IN2,IN3,IN4;

    public:
        Motores(int a,int b,int c,int d );
        void frente();
        void tras();
        void direita();
        void esquerda();
        void parar ();
};

#endif
