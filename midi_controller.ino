#include "ButtonManager.h"
#include "MenuManager.h"
#include "Wire.h"
#include "Adafruit_LiquidCrystal.h"

Adafruit_LiquidCrystal lcd(0);

ButtonManager ButtonManager(D5, D6, D7, D8); // Button A, B, C, and D pins
MenuManager MenuManager(&lcd);

void setup() {
  Serial.begin(9600);
  
  Wire.begin(D2, D1);
  lcd.begin(20, 4);
}

void loop() {
  MenuManager.handleInteraction(ButtonManager.getAccumulatedButtonState());
}
