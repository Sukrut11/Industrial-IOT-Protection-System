#include <DHT.h>
#include <LiquidCrystal.h>
#define dht_apin 6 // Analog Pin sensor is connected to
#define DHTTYPE DHT11
#define DHT11_PIN 6
DHT dht(DHT11_PIN, DHTTYPE); 
LiquidCrystal lcd(8,9,10,11,12,13);
int gas = 0;
int buzzer = 13;
const int gasSensor = A0;
int thre = 2000;
int mot1 = 9;
int mot2 = 10;
int temp = 6;
float threshold_temp = 50;
int baselineTemp = 0;
int celsius = 0;
int fahrenheit = 0;
const int ledPin = 22;
const int ldrPin = A0;
const int lamp = 8;
void setup()
{
  dht.begin();
  lcd.begin(16, 2);
  // Print a message to the LCD.
  pinMode(buzzer,OUTPUT );
  pinMode(gasSensor,INPUT );
  pinMode(mot1,OUTPUT );
  pinMode(mot2,OUTPUT );
  pinMode(lamp,OUTPUT );
  pinMode(ldrPin , INPUT);
  Serial.begin(9600);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Mini Project");
  delay(40);
  lcd.clear();
  dht.begin();
  Serial.begin(9600);
}
void loop()
{
 gas  = analogRead(gasSensor);
  //print the input om serial monitor 
  int led_out = map(gas, 80, 400, 0, 255); 
  lcd.setCursor(1, 0);
  lcd.print("Gas :");
    lcd.setCursor(6, 0);
    lcd.print(gas);
    Serial.println(gas);
  if(gas > thre)
  {
    digitalWrite(mot2, HIGH);
  // print the number of seconds since reset:
    tone(buzzer,1000,10000);
  //send the pwm signal to led
  //delay of 1000ms
     delay(30);
    lcd.clear();
  } 
  else 
  { 
    digitalWrite(mot2, LOW);
    noTone(buzzer);
  }
   
    DHT.read11(DHT11_PIN);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
}
