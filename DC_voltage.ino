#include <LiquidCrystal_I2C.h>
#define NUM_SAMPLES 10

LiquidCrystal_I2C lcd(0x27, 20, 4);

int analogInput = A2;
float vout = 0.0;
float vin = 0.0;
float R1 = 440.0;
float R2 = 220.0;
int value = 0;
int Buzzer = 8;
int sum = 0;
unsigned char sample_count = 0;


void setup() {
  pinMode(A0, INPUT);
  pinMode(Buzzer, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 2);
  lcd.print("DC VOLTMETER");
  Serial.begin(9600);
  lcd.clear();
}

void loop() {
  vout = (analogRead(A0) * 5.0) / 1024.0;
  vin = vout / (R2 / (R1 + R2));

  if (vin < 5) {
    digitalWrite(Buzzer, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("INPUT V= ");
    lcd.print(vin);
    lcd.setCursor(0, 2);
    lcd.print("BATT LOW");
    Serial.print(vin);
    delay(500);
  } else {
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("INPUT V= ");
    lcd.print(vin);
    Serial.println(vin);
    delay(500);
  }
}
