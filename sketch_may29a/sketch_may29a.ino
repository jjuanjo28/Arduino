#include<Servo.h>
#define DEBUG(a) Serial.println(a);
Servo motor;

void setup() {
 Serial.begin(9600); 
 motor.attach(3);
 Serial.println("inicilizando comunicacion"); 
}

void loop() {

   while(Serial.available()){
   // char val = Serial.read();
   // Serial.println(val);
   int data = Serial.parseInt();
//   int newData = DEBUG((int)data);
  // Serial.println(newData);
   

  switch(data) {
        
        case 1: motor.write(15);
                 Serial.println("estoy en 15 que es la 1");
                 return; 
        case 2: motor.write(30);
                 Serial.println("estoy en 30 que es la 2");
                 return;
        case 3: motor.write(45);
                 Serial.println("estoy en 45 que es la 3");
                 return;
        case 4: motor.write(60);
                 Serial.println("estoy en 60 que es la 4");
                 return;
        case 5 : motor.write(75);
                 Serial.println("estoy en 75 que es la 5");
                 return;
        case 6: motor.write(90);
                 Serial.println("estoy en 90 que es la 6");
                 return;
        case 7: motor.write(105);
                 Serial.println("estoy en 105 que es la 7");
                 return;
        case 8: motor.write(120);
                 Serial.println("estoy en 120 que es la 8");
                 return; 
        case 9: motor.write(135);
                 Serial.println("estoy en 135 que es la 9");
                 return;
        case 10: motor.write(150);
                 Serial.println("Estoy en 150 que es la 10");
                 return;  
        case 11: motor.write(165);
                 Serial.println("Estoy en 165 que es la 11");
                 return;   
        case 12: motor.write(180);
                 Serial.println("Estoy en 180 que es la 12");
                 return;                            
                 
       
      }

   
   }
}   
 
  
  
