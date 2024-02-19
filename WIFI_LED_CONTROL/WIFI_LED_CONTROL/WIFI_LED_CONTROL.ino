#include <ESP8266WiFi.h>    
#include <Adafruit_Sensor.h>
#include <DHT.h>



const char* ssid = "Fibertel WiFi014 2.4GHz";
const char* password = "0042502821";  
  
WiFiServer server(80); 

static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;                 
 
#define DHTPIN D4 
#define DHTTYPE DHT11                 
int estadoRojo = 0;
int estadoAmarillo = 0; 
int estadoVerde = 0;
char entrada;
 unsigned long previousMillis = 0;                   
DHT dht(DHTPIN, DHTTYPE); 
uint32_t delayMS;
unsigned long timeout = millis();

void setup() {
  Serial.begin(115200);
 
  pinMode(D3, OUTPUT);              
  pinMode(D2, OUTPUT);
 
  pinMode(D5, OUTPUT); 
  dht.begin();
  
   
  WiFi.begin(ssid, password);           
  Serial.printf("\n\nConectando a la red: %s\n", WiFi.SSID().c_str());
   while (WiFi.status() != WL_CONNECTED) { 
    delay(100);
    Serial.print(".");                    
  }
  Serial.println("");
  Serial.println("WiFi conectada");       
 
  server.begin();    
  Serial.println("Servidor inicializado");
 
 Serial.printf("\n\nUtiliza esta URL para conectar: http://%s/\n", WiFi.localIP().toString().c_str());
 
  } 
 
void loop() 
{
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humedad: ");
  Serial.println(h);
  Serial.print("Temperatura: ");
  Serial.println(t);
  
  
  if(Serial.available()){
    delay(50);
    while(Serial.available()>0){
      entrada = Serial.read();
      Serial.println(entrada);
      switch(entrada){
        case '1' :
         estadoVerde = HIGH;
         Serial.println(estadoVerde);
         Serial.println(D3);
         digitalWrite(D3, estadoVerde);
         break;
       case '2' :
         estadoVerde = LOW;
         Serial.println(estadoVerde);
         Serial.println(D3);
         digitalWrite(D3, estadoVerde);
         break;
        case '3' :
         estadoAmarillo = HIGH;
         Serial.println(estadoAmarillo);
         Serial.println(D2);
         digitalWrite(D2, estadoAmarillo);
         break;
       case '4' :
         estadoAmarillo = LOW;
         Serial.println(estadoAmarillo);
         Serial.println(D2);
         digitalWrite(D2, estadoVerde);
         break;
        case '5' :
         estadoRojo = HIGH;
         Serial.println(estadoRojo);
         Serial.println(D5);
         digitalWrite(D5, estadoRojo);
         break;
       case '6' :
         estadoRojo = LOW;
         Serial.println(estadoRojo);
         Serial.println(D5);
         digitalWrite(D5, estadoRojo);
         break;    
       default: return;  
     
      }
    }
  }
   
  
  

  WiFiClient client = server.available();  
  if (!client) {
    return;
  }
 

  Serial.println("nuevo cliente");
  while(!client.available()){
    delay(1);
  }
  unsigned long currentMillis = millis();
 

  

     String peticion = client.readStringUntil('\r');
  Serial.println(peticion);
  client.flush();
 


  if (peticion == "GET /LEDGREEN=ON HTTP/1.1") 
  {estadoVerde = LOW;
   Serial.println(estadoVerde);
   Serial.println(D3);
  } 
  if (peticion == "GET /LEDGREEN=OFF HTTP/1.1")
  {estadoVerde = HIGH;
   Serial.println(estadoVerde);
   Serial.println(D3);
  }

 if (peticion == "GET /LEDYELLOW=ON HTTP/1.1") 
  {estadoAmarillo = LOW;
   Serial.println(estadoAmarillo);
   Serial.println(D2);
  } 
  if (peticion == "GET /LEDYELLOW=OFF HTTP/1.1")
  {estadoAmarillo = HIGH;
   Serial.println(estadoAmarillo);
   Serial.println(D2);
  }

  
  if (peticion == "GET /LEDRED=ON HTTP/1.1")
  {estadoRojo = LOW;
   Serial.println(estadoRojo);
   Serial.println(D5);
  }
  
  if (peticion == "GET /LEDRED=OFF HTTP/1.1")
  {estadoRojo = HIGH;
   Serial.println(estadoRojo);
   Serial.println(D5);
  }
  
  digitalWrite(D3, estadoVerde);
 digitalWrite(D2, estadoAmarillo);
digitalWrite(D5, estadoRojo);
 // client.println("HTTP/1.1 200 OK");
  client.println("");                         
  client.println("");
  client.println("");
  client.println("");

  client.print("<h1 align=center>CONTROL LED VERDE ");
 
 if(estadoVerde == HIGH) 
 {client.print("<input type='image' src='https://i.imgur.com/00i0BdB.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDGREEN=ON'>");}
 else 
 {client.print("<input type='image' src='https://i.imgur.com/uQxhFE5.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDGREEN=OFF'>");}

client.print("<h1 align=center>CONTROL LED AMARILLO ");
 if(estadoAmarillo == HIGH) 
 {client.print("<input type='image' src='https://i.imgur.com/00i0BdB.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDYELLOW=ON'>");}
 else 
 {client.print("<input type='image' src='https://i.imgur.com/uQxhFE5.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDYELLOW=OFF'>");}

client.print("<h1 align=center>CONTROL LED ROJO ");
 if(estadoRojo == HIGH) 
 {client.print("<input type='image' src='https://i.imgur.com/00i0BdB.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDRED=ON'>");}
 else 
 {client.print("<input type='image' src='https://i.imgur.com/uQxhFE5.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDRED=OFF'>");}
 
 

 
 client.println("</html>");
 delay(1);
 Serial.println("Peticion finalizada"); // Se finaliza la petición al cliente. Se inicializa la espera de una nueva petición.
 Serial.println("");
 
}
