#include <Arduino.h>

#define WATER_SENSOR_PIN    A0
#define VCC_SENSOR_PIN      22

/**
 * Read from sensor. 
 */
float readFromSensor();

void setup() {
    pinMode(WATER_SENSOR_PIN, INPUT);
    pinMode(VCC_SENSOR_PIN, OUTPUT);

    Serial.begin(9600);
}

void loop() {
    // Test
    float waterLevel = readFromSensor();
    Serial.print("Water level: ");
    Serial.print(waterLevel);
    Serial.print("\n");
    delay(2000);
}

#pragma region Sensore

float readFromSensor() {
    // Accendi il sensore
    digitalWrite(VCC_SENSOR_PIN, HIGH);

    // Leggi il valore
    delay(20);
    float value = analogRead(VCC_SENSOR_PIN);

    // Spegni il sensore
    digitalWrite(VCC_SENSOR_PIN, LOW);

    // Ritorna il valore letto
    return value;
}

#pragma endregion
