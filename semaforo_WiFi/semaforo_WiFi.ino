
#include <ESP8266WiFi.h>

const char *ssid = "Fibertel WiFi014 2.4GHz";
const char *password = "0042502821";

WiFiServer server(80);

static const uint8_t D0 = 16;
static const uint8_t D1 = 5;
static const uint8_t D2 = 4;
static const uint8_t D3 = 0;
static const uint8_t D4 = 2;
static const uint8_t D5 = 14;
static const uint8_t D6 = 12;
static const uint8_t D7 = 13;
static const uint8_t D8 = 15;
static const uint8_t D9 = 3;
static const uint8_t D10 = 1;

int estadoGreen = 0;
int estadoRed = 0;
int estadoYellow = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(D3, OUTPUT);
     pinMode(D2, OUTPUT);
      pinMode(D4, OUTPUT);

    WiFi.begin(ssid, password);
    Serial.printf("\n\nConectando a la red: %s\n", WiFi.SSID().c_str());
    while (WiFi.status() != WL_CONNECTED)
    {
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

    WiFiClient client = server.available();
    if (!client)
    {
        return;
    }

    Serial.println("nuevo cliente");
    while (!client.available())
    {
        delay(1);
    }

    String peticion = client.readStringUntil('\r');
    Serial.println("aca tentes tu peticion: ");
    Serial.println(peticion);
    client.flush();

    if(peticion == "GET /LEDGREEN=ON HTTP/1.1"){
        estadoGreen = HIGH;
        Serial.println(estadoGreen);
        Serial.println(D3);
    }
    
    if(peticion == "GET /LEDGREEN=OFF HTTP/1.1"){
        estadoGreen = LOW;
        Serial.println(estadoGreen);
        Serial.println(D3);
    }
    
     if (peticion.indexOf('/LEDRED=ON') != -1)
    {
        estadoRed = LOW;
        Serial.println("red on");
        Serial.println(estadoRed);
        Serial.println(D4);
    }
    if (peticion.indexOf('/LEDRED=OFF') != -1)
    {
        estadoRed = HIGH;
        Serial.println("red off");
        Serial.println(estadoRed);
        Serial.println(D4);
    }
 
    digitalWrite(D4, estadoRed);
    digitalWrite(D3, estadoGreen);
     digitalWrite(D2, estadoYellow);

    client.println("HTTP/1.1 200 OK");
    client.println("");
    client.println("");
    client.println("");
    client.println("");

    client.print("<h1 align=center>CONTROL LED GREEN ");

    if (estadoGreen == HIGH)
    {
        client.print("<input type='image' src='https://i.imgur.com/00i0BdB.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDGREEN=ON'>");
    }
    else
    {
        client.print("<input type='image' src='https://i.imgur.com/uQxhFE5.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDGREEN=OFF'>");
    }

    client.print("<h1 align=center>CONTROL LED RED ");
     if (estadoRed == HIGH)
    {
        client.print("<input type='image' src='https://i.imgur.com/00i0BdB.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDRED=ON'>");
    }
    else
    {
        client.print("<input type='image' src='https://i.imgur.com/uQxhFE5.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDRED=OFF'>");
    }

    client.print("<h1 align=center>CONTROL LED YELLOW ");
     if (estadoYellow == HIGH)
    {
        client.print("<input type='image' src='https://i.imgur.com/00i0BdB.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDYELLOW=ON'>");
    }
    else
    {
        client.print("<input type='image' src='https://i.imgur.com/uQxhFE5.jpg' style='display:block; margin:auto' width='30%' onClick=location.href='/LEDYELLOW=OFF'>");
    }

    client.println("</html>");
    delay(1);
    Serial.println("Peticion finalizada"); // Se finaliza la petición al cliente. Se inicializa la espera de una nueva petición.
    Serial.println("");
}
