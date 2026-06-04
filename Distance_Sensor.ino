#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigPin = 5; // D5  
int echoPin = 3; // D3

void setup() {
  lcd.init();
  lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.setCursor(0, 0);
  lcd.print("Initialisation");
  delay(1000);
  lcd.clear();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2; // en Serial.begin(9600); 0.035/2

  lcd.setCursor(0, 0);
  lcd.print("Distance:      ");
  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm     ");

  delay(10);
}
