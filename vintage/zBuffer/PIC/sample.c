Sample Arduino Code :
#include <LiquidCrystal.h> // For 16x2 LCD

void loop() {
    if (digitalRead(SENSOR_PIN) == LOW) { 
        // IR beam interrupted
        count++;
        lcd.setCursor(0, 1);
        lcd.print(count);
        Serial.print("Count: ");
        Serial.println(count);
        delay(500); // Prevent multiple detections of one fruit
    }
}



