#include <LiquidCrystal.h>
#include <DHT.h>


#define DHTPIN 8
#define DHTTYPE DHT11

float humedad;
float temperaturaC;
float temperaturaF;
float sensacionC;
float sensacionF;
float total[10];

int YellowPin = 9;
int RedPin = 11;

LiquidCrystal lcd(7,6,5,4,3,2);
DHT sensorDHT(DHTPIN, DHTTYPE);



void setup() {
  
 Serial.begin(9600);
 
 pinMode(YellowPin, OUTPUT);
 pinMode(RedPin, OUTPUT);
 Serial.println("inicilizando comunicacion"); 
 
 sensorDHT.begin();
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("Verificador de");
 lcd.setCursor(0,1);
 lcd.print("humedad y temperatura");
 delay(2500);

}

void loop() {
  
  
    
  while(Serial.available()){
    char val = Serial.read();
    if(val == '1'){
      digitalWrite(YellowPin, HIGH);
      } else if(val == '2'){
      digitalWrite(YellowPin, LOW);
      }
    if(val == '3') {
    digitalWrite(RedPin, HIGH) ; 
   } else if(val == '4') {
     digitalWrite(RedPin, LOW);
   }
  
  }
 
  

  
  humedad = sensorDHT.readHumidity();
  temperaturaC =sensorDHT.readTemperature();
  temperaturaF = sensorDHT.readTemperature(true);
  total[0] = temperaturaC;
  total[1] = humedad;
 
  
  if ( isnan(humedad) || isnan(temperaturaC) || isnan(temperaturaF) ) {
      lcd.clear();
      lcd.setCursor(0,0);
     lcd.print("error en la lectura del sensor");
    return;
  };
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperatura: ");
  lcd.setCursor(12,0);
  lcd.print(temperaturaC);
  lcd.setCursor(0,1);
  lcd.print("Humedad: ");
  lcd.setCursor(9,8);
  lcd.print(humedad);
  lcd.print("%");
  
  if( humedad > 55 ){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PELIGRO EXCESO");
    lcd.setCursor(0,1);
    lcd.print("HUMEDAD!!!!");
  }
  Serial.print("Temperatura: ");
  Serial.println(total[0]);
  delay(1250);
  Serial.print("Humedad: ");
  Serial.println(total[1]);
 
 delay(1250);

}
