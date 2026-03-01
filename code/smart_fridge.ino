#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define REED_PIN 7
#define BUZZER_PIN 8
#define GAS_PIN A0

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

unsigned long doorOpenTime = 0;
bool doorWasOpen = false;

int gasThreshold = 450;

void setup() {
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.begin();
  lcd.backlight();

  Serial.begin(9600);
  dht.begin();

  lcd.setCursor(0, 0);
  lcd.print("  Smart Fridge");
  lcd.setCursor(0, 1);
  lcd.print("    Starting");
  delay(2000);
  lcd.clear();
}

void loop() {

  int reedState = digitalRead(REED_PIN);
  int gasValue = analogRead(GAS_PIN);
  float temperature = dht.readTemperature();

  // ===== DOOR LOGIC =====
  bool doorOpen = (reedState == HIGH);

  if (doorOpen) {
    if (!doorWasOpen) {
      doorOpenTime = millis();
      doorWasOpen = true;
    }

    if (millis() - doorOpenTime >= 60000) {
      digitalWrite(BUZZER_PIN, HIGH);
    }
  } else {
    doorWasOpen = false;
    digitalWrite(BUZZER_PIN, LOW);
  }

  // ===== GAS ALERT =====
  if (gasValue > gasThreshold) {
    digitalWrite(BUZZER_PIN, HIGH);
  }

  // ===== LCD DISPLAY =====
  lcd.clear();

  // Line 1: Door + GOOD/BAD
  lcd.setCursor(0, 0);
  lcd.print("Door:");

  if (doorOpen) {
    lcd.print("OPEN ");
  } else {
    lcd.print("CLOSE ");
  }

  if (gasValue > gasThreshold) {
    lcd.print(" BAD");
  } else {
    lcd.print(" GOOD");
  }

  
  lcd.setCursor(0, 1);

  lcd.print("T:");
  if (!isnan(temperature)) {
    lcd.print(temperature);
    lcd.print("C ");
  } else {
    lcd.print("Err ");
  }

  lcd.print("Gas:");
  lcd.print(gasValue);

  delay(2000);
}
