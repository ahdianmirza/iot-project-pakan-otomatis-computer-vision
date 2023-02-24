#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>
#include <Servo.h>

// Ultrasonic Pin
const int trigPin = 5;
const int echoPin = 18;

// LCD Pin
int lcdColumns = 16;
int lcdRows = 2;

// Ultrasonic Variable
long duration;
float distanceCm;

// RTC inisialisasi pin (CLK, DAT, RST)
virtuabotixRTC myRTC(14, 12, 27);

// Servo
Servo myServo;
int pos = 0;

LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);

// Pemanggilan fungsi
void rtc();
void ultrasonic();
void servo();

void setup()
{
  Serial.begin(9600);

  // Servo pin
  myServo.attach(13);

  // detik, menit, jam, hari dalam seminggu, tanggal, bulan, tahun
  myRTC.setDS1302Time(00, 41, 17, 6, 24, 2, 2023);

  // Ultrasonic pinMode
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.begin();
  lcd.backlight();
}

void loop()
{
  rtc();
  ultrasonic();
  servo();
}
