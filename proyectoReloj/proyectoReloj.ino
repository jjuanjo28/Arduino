#include<Servo.h>
#define DEBUG(a) Serial.println(a);
Servo motor;
Servo motorDos;
Servo motorTres;
void setup() {
 Serial.begin(9600); 
 motor.attach(3);
 motorDos.attach(4);
 motorTres.attach(7);
 Serial.println("inicilizando comunicacion"); 
}

void loop() {

   while(Serial.available()){
  
   int data = Serial.parseInt();

   

  switch(data) {
        
    case 1:
      motor.write(3);
       return;
    case 2:
      motor.write(6);
     
      return;
    case 3:
      motor.write(9);
     
      return;
    case 4:
      motor.write(12);
      
      return;
    case 5:
      motor.write(15);
    
      return;
    case 6:
      motor.write(18);
     
      return;
    case 7:
      motor.write(21);
    
      return;
    case 8:
      motor.write(24);
    
      return;
    case 9:
      motor.write(27);
    
      return;
    case 10:
      motor.write(30);
      
      return;
    case 11:
      motor.write(33);
     
      return;
    case 12:
      motor.write(36);
      
      return;
    case 13:
      motor.write(39);
     
      return;
    case 14:
      motor.write(42);
     
      return;
    case 15:
      motor.write(45);
     
      return;
    case 16:
      motor.write(48);
      
      return;
    case 17:
      motor.write(51);
     
      return;
    case 18:
      motor.write(54);
     
      return;
    case 19:
      motor.write(57);
     
      return;
    case 20:
      motor.write(60);
     
      return;
    case 21:
      motor.write(63);
     
      return;
    case 22:
      motor.write(66);
      
      return;
    case 23:
      motor.write(69);
     
      return;
    case 24:
      motor.write(72);
     
      return;
    case 25:
      motor.write(75);
     
      return;
    case 26:
      motor.write(78);
     
      return;
    case 27:
      motor.write(81);
    
      return;
    case 28:
      motor.write(84);
      
      return;
    case 29:
      motor.write(87);
      
      return;
    case 30:
      motor.write(90);
      
      return;
    case 31:
      motor.write(93);
      
      return;
    case 32:
      motor.write(96);
      
      return;
    case 33:
      motor.write(99);
      
      return;
    case 34:
      motor.write(102);
      
      return;
    case 35:
      motor.write(105);
      
      return;
    case 36:
      motor.write(108);
      
      return;
    case 37:
      motor.write(111);
      
      return;
    case 38:
      motor.write(114);
      
      return;
    case 39:
      motor.write(117);
     
      return;
    case 40:
      motor.write(120);
     
      return;
    
    case 41:
      motor.write(123);
      
      return;
    case 42:
      motor.write(126);
     
      return;
    case 43:
      motor.write(129);
      
      return;
    case 44:
      motor.write(132);
      
      return;
    case 45:
      motor.write(135);
      
      return;
    case 46:
      motor.write(138);
      
      return;
    case 47:
      motor.write(141);
      
      return;
    case 48:
      motor.write(144);
     
      return;
    case 49:
      motor.write(147);
     
      return;
    case 50:
      motor.write(150);
      
      return;
    case 51:
      motor.write(153);
     
      return;
    case 52:
      motor.write(156);
      
      return;
    case 53:
      motor.write(159);
      
      return;
    case 54:
      motor.write(162);
    
      return;
    case 55:
      motor.write(165);
      
      return;
    case 56:
      motor.write(168);
     
      return;
    case 57:
      motor.write(171);
     
      return;
    case 58:
      motor.write(174);
     
      return;
    case 59:
      motor.write(177);
     
      return;
    case 60:
      motor.write(180);
       return;                    
        case 61:
         motorDos.write(3);
        
         return;      

      
       case 62:
         motorDos.write(6);
        
         return;
       case 63:
         motorDos.write(9);
        
         return;
       case 64:
         motorDos.write(12);
         
         return;
       case 65:
         motorDos.write(15);
       
         return;
       case 66:
         motorDos.write(18);
        
         return;
       case 67:
         motorDos.write(21);
       
         return;
       case 68:
         motorDos.write(24);
       
         return;
       case 69:
         motorDos.write(27);
       
         return;
       case 70:
         motorDos.write(30);
         
         return;
       case 71:
         motorDos.write(33);
        
         return;
       case 72:
         motorDos.write(36);
         
         return;
       case 73:
         motorDos.write(39);
        
         return;
       case 74:
         motorDos.write(42);
        
         return;
       case 75:
         motorDos.write(45);
        
         return;
       case 76:
         motorDos.write(48);
         
         return;
       case 77:
         motorDos.write(51);
        
         return;
       case 78:
         motorDos.write(54);
        
         return;
       case 79:
         motorDos.write(57);
        
         return;
       case 80:
         motorDos.write(60);
        
         return;
       case 81:
         motorDos.write(63);
        
         return;
       case 82:
         motorDos.write(66);
         
         return;
       case 83:
         motorDos.write(69);
        
         return;
       case 84:
         motorDos.write(72);
        
         return;
       case 85:
         motorDos.write(75);
        
         return;
       case 86:
         motorDos.write(78);
        
         return;
       case 87:
         motorDos.write(81);
       
         return;
       case 88:
         motorDos.write(84);
         
         return;
       case 89:
         motorDos.write(87);
         
         return;
       case 90:
         motorDos.write(90);
         
         return;
       case 91:
         motorDos.write(93);
         
         return;
       case 92:
         motorDos.write(96);
         
         return;
       case 93:
         motorDos.write(99);
         
         return;
       case 94:
         motorDos.write(102);
         
         return;
       case 95:
         motorDos.write(105);
         
         return;
       case 96:
         motorDos.write(108);
         
         return;
       case 97:
         motorDos.write(111);
         
         return;
       case 98:
         motorDos.write(114);
         
         return;
       case 99:
         motorDos.write(117);
        
         return;
       case 100:
         motorDos.write(120);
        
         return;
       
       case 101:
         motorDos.write(123);
         
         return;
       case 102:
         motorDos.write(126);
        
         return;
       case 103:
         motorDos.write(129);
         
         return;
       case 104:
         motorDos.write(132);
         
         return;
       case 105:
         motorDos.write(135);
         
         return;
       case 106:
         motorDos.write(138);
         
         return;
       case 107:
         motorDos.write(141);
         
         return;
       case 108:
         motorDos.write(144);
        
         return;
       case 109:
         motor.write(147);
        
         return;
       case 110:
         motorDos.write(150);
         
         return;
       case 111:
         motorDos.write(153);
        
         return;
       case 112:
         motorDos.write(156);
         
         return;
       case 113:
         motorDos.write(159);
         
         return;
       case 114:
         motorDos.write(162);
       
         return;
       case 115:
         motorDos.write(165);
         
         return;
       case 116:
         motorDos.write(168);
        
         return;
       case 117:
         motorDos.write(171);
        
         return;
       case 118:
         motorDos.write(174);
        
         return;
       case 119:
         motorDos.write(177);
        
         return;
       case 120:
         motorDos.write(180);
          return;
        
       case 121:
         motorTres.write(15);
         
         return;
       case 122:
         motorTres.write(30);
         
         return;
       case 123:
         motorTres.write(45);
       
         return;
       case 124:
         motorTres.write(60);
         
         return;
       case 125:
         motorTres.write(75);
        
         return;
       case 126:
         motorTres.write(90);
        
         return;
       case 127:
         motorTres.write(105);
        
         return;
       case 128:
         motorTres.write(120);
        
         return;
       case 129:
         motorTres.write(135);
          return;
        
         return;
       case 130:
         motorTres.write(150);
        
         return;
       case 131:
         motorTres.write(165);
          return;  
             return;
       case 132:
         motorTres.write(180);
          return;       
      }

   
   }
}   
 
  
  
