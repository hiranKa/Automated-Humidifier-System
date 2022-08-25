#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define USB_PORT_ONE 11
#define USB_PORT_TWO 12

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(A0, INPUT_PULLUP);
  pinMode(USB_PORT_ONE, OUTPUT);
  pinMode(USB_PORT_TWO, OUTPUT);
  lcd.setCursor(0,0);
  lcd.print("AUTO-HUMIDIFIER");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(A0)==0)
  {
    lcd.setCursor(0,1);
    lcd.print("SENSOR STA-[ON ]");
    digitalWrite(USB_PORT_ONE, HIGH);
    digitalWrite(USB_PORT_TWO, HIGH);    
  }else
  {
    lcd.setCursor(0,1);
    lcd.print("SENSOR STA-[OFF]");
    digitalWrite(USB_PORT_ONE, LOW);
    digitalWrite(USB_PORT_TWO, LOW);
  }
}

