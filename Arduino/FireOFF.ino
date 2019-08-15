#include <dht.h>
#include "Buzzer.h"
#include "Motores.h"
dht DHT;
int temp = A1;
int sensor = A0;
Buzzer buzzer (9);
Motores Motores (4,5,7,8);

const String MOTOR = "\"MOTOR\":";
const String TEMP = "\"TEMP\":";
const String BUZZER = "\"BUZZER\":";
const String SENSOR = "\"SENSOR\":";
const String BT_OFFA = "\"BT_OFFA\":";
int leitura_sensor = 300;// valor de desame do sensor
uint32_t timer = 0;
int sensor_value = 0;
int sensorDht =0;

String JSON_TEMP(){ // Função que retorna do sensot de temp
DHT.read11(temp);

int sensorDht = DHT.temperature;
   return "{" +
      TEMP + String(sensorDht) +
      "}";
 }

 
String JSON_BUZZER(){ // Função que retorna do BUZZER

   return "{" +
      BUZZER + String(buzzer.status()) +
      "}";
 }

String JSON_SENSORGAS(){ // Função que retorna o valor medido pelo sensor MQ-2
 int sensor_value = analogRead(sensor);
   sensor_value = map(sensor_value, 0, 1023, 0, 100);
 
    return "{" +
      SENSOR + String(sensor_value) +
      "}";
}
void desligarA(String comando){ // Função para desligar o alarme
  // if(comando.indexOf("{") && comando.indexOf("}")){
      if(comando.indexOf(BT_OFFA + " 0") > 0){
          buzzer.desligar(); //  desligar o Buzzerbuzzer.desligar()
          sensor_value = 30;
      }
       else if(comando.indexOf(BT_OFFA + " 1") > 0){
           //  desligar o Buzzerbuzzer.desligar()
          int i=0;
          while(i<50){
          buzzer.acionar();
          delay(100);
          buzzer.desligar();
          delay(100);
          i=i+1;
          }
          
      }
   //}

}

void Lmotor(String comando){// ACIONAMENTO DOS MOTORES
  
  if(comando.indexOf(MOTOR + " 1") > 0){// ir para frente
    Motores.frente();
    }

  if(comando.indexOf(MOTOR + " 2") > 0){
       Motores.tras();
    }

  if(comando.indexOf(MOTOR + " 3") > 0){

    Motores.direita();
  }
  if(comando.indexOf(MOTOR + " 4") > 0){
    Motores.esquerda();
  
  }
  if(comando.indexOf(MOTOR + " 5") > 0){
    Motores.parar();
  
  }
  
  }







void setup (){
  pinMode(sensor, INPUT);
  Serial.begin(115200);

  }

  void loop(){

    DHT.read11(temp);
    int sensorDht = DHT.temperature;
    
    int  sensor_value = analogRead(sensor);
   if(Serial.available() > 0){ // Verifica se há algo na barra de comando serial
        String comando = Serial.readString();
        desligarA(comando);
        Lmotor(comando);
        Serial.print (comando);
        Serial.print(JSON_SENSORGAS());
        delay(10);
        Serial.print(JSON_BUZZER());

  }

   Serial.print(JSON_SENSORGAS());
   delay(20);
   Serial.print(JSON_BUZZER());
    delay(20);
Serial.print(JSON_TEMP());
    delay(20);
    if(sensor_value > leitura_sensor ) 
  {
    buzzer.acionar(); // Metódo da classe Buzzer.h para acionar o BUZZER
    Serial.print(JSON_SENSORGAS());
    delay(20);
    Serial.print(JSON_BUZZER());
    delay(20);
    
  
      if(Serial.available() > 0){
        String comando = Serial.readString();
        desligarA(comando);
        Serial.print(JSON_SENSORGAS());
        delay(10);
        Serial.print(JSON_BUZZER());
      
    }
     sensor_value = analogRead(sensor);
     delay (10000);
  }
  if (sensor_value < leitura_sensor ){
    
    
    buzzer.desligar();  
  }
  
delay(300);
 
   
  
}
   

    
