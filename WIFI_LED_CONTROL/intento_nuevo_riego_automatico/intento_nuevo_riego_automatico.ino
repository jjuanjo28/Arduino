



#include <ArduinoJson.h>

#include <ESP8266Firebase.h>



#include <ESP8266WiFi.h>    




const char* ssid = "Fibertel WiFi014 2.4GHz";
const char* password = "0042502821";  

#define FIREBASE_HOST "cultivo-c71e7-default-rtdb.firebaseio.com"
//#define FIREBASE_AUTH "2CFVBxtVIypGhxCWLOxLGP5WWMoV7ywNpApFd2bP"
Firebase firebase(FIREBASE_HOST);


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
int bombaRiego = D7;
int ledVerde = D5;
int sensorPin = A0;
int humedadSuelo;
void setup() {
  Serial.begin(115200);
 
  pinMode(ledVerde, OUTPUT);              
  pinMode(ledRojo, OUTPUT);
  pinMode(bombaRiego, OUTPUT);
  digitalWrite(bombaRiego, HIGH);
   
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
  firebase.setInt("HumedadSuelo/setInt", humedadSuelo);
  Serial.print("Humedad: ");
  Serial.println(humedadSuelo);
  int data2 = firebase.getInt("HumedadSuelo/setInt");
  Serial.print("desde la base la humedad es:\t\t");
  Serial.println(data2);
  
  int luz = firebase.getInt("luz");
  Serial.print("soy luz: ");
  Serial.println(luz);
  
  if( luz == 1 && humedadSuelo < 700){
    firebase.setInt("estadoBomba", 1);
    firebase.setInt("luz",1);
    Serial.println("Me obligaron a regar!!!!");
    digitalWrite(ledRojo,HIGH);
    digitalWrite(bombaRiego, LOW);
    delay(5000);
    digitalWrite(ledRojo,LOW);
    digitalWrite(bombaRiego,HIGH);
    Serial.println("YA CORTE DE OBLIGADO");
    firebase.setInt("estadoBomba", 0);
    firebase.setInt("luz", 0);
    
   } 
  
 
if(humedadSuelo > 700 && luz == 0){
   
   digitalWrite(ledVerde, LOW);
   digitalWrite(ledRojo, HIGH);
   digitalWrite(bombaRiego, LOW);
   firebase.setInt("estadoBomba", 1);
   Serial.println("Me puse a regar!!!");
  
   delay(500);
   
   
 } 
 
 if(humedadSuelo < 700 && luz == 0){
     digitalWrite(bombaRiego, HIGH);
     digitalWrite(ledVerde, HIGH);
     digitalWrite(ledRojo, LOW);
     firebase.setInt("estadoBomba",0);
     delay(500);
     }
 
 
    
  }
   
  
  


 
