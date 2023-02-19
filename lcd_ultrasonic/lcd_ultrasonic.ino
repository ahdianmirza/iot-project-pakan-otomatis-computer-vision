#include <LiquidCrystal_I2C.h>

// Ultrasonic Pin
const int trigPin = 5;
const int echoPin = 18;

// LCD Pin
int lcdColumns = 16;
int lcdRows = 2;

// Ultrasonic Variable
long duration;
float distanceCm;
 
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceCm = (duration/2) / 27.6;

  lcd.setCursor(0, 0);
  lcd.print("Jarak: ");

  lcd.setCursor(0, 1);
  lcd.print(distanceCm);
}
