#include<LiquidCrystal.h>
const int tmp=A0,buzz=7;//temperature sensor and piezo buzzer
LiquidCrystal lcd(12,11,5,4,3,2);//LCD initialized in  bit write mode

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.home();
  pinMode(buzz,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.print("Temperature:-");
  lcd.setCursor(0,1);
  float t_c=(5.0*analogRead(tmp)*100.0)/1024,t_f=(t_c*9/5)+32;
  if(t_c>50)
    digitalWrite(buzz,HIGH);
  else
    digitalWrite(buzz,LOW);
  lcd.print(t_c);
  lcd.print("'C ");
  lcd.print(t_f);
  lcd.print("'F");
  delay(500);
}
