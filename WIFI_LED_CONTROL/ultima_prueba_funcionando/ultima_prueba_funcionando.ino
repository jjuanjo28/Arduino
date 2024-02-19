#include <ESP8266WiFi.h>    





const char* ssid = "Fibertel WiFi014 2.4GHz";
const char* password = "0042502821";  
  
WiFiServer server(80); 

static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;                 
 
                
int ledRojo = D6;

int ledVerde = D5;
int sensorPin = A0;
int humedadSuelo;
void setup() {
  Serial.begin(115200);
 
  pinMode(ledVerde, OUTPUT);              
  pinMode(ledRojo, OUTPUT);
 
  
   
  WiFi.begin(ssid, password);           
  Serial.printf("\n\nConectando a la red: %s\n", WiFi.SSID().c_str());
   while (WiFi.status() != WL_CONNECTED) { 
    delay(100);
    Serial.print(".");                    
  }
  Serial.println("");
  Serial.println("WiFi conectada");       
 
      

 
 
 
  } 
 
void loop() 
{
  delay(1000);
  humedadSuelo = analogRead(sensorPin);
  Serial.print("Humedad: ");
  Serial.println(humedadSuelo);

if(humedadSuelo > 700){
   
   digitalWrite(ledVerde, LOW);
   digitalWrite(ledRojo, HIGH);
  
   delay(500);
   
 } else {
   
     digitalWrite(ledVerde, HIGH);
     digitalWrite(ledRojo, HIGH);
     delay(500);
     }
 
 delay(1000);
  
  
  
    
  }
   
  
  


 
