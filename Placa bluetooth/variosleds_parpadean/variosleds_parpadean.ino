int led1 = 8;
int led2 = 7;
int led3 = 12;

void setup() {
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
}

void blinkAllLeds() {
    for (int i = 0; i < 10; i++) { // Parpadea 10 veces
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        delay(500);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        delay(500);
    }
}

void loop() {
    if (Serial.available() > 0) {
        char data = Serial.read();
        
        if (data == 'a') {
            Serial.println("All LEDs Parpadean");
            blinkAllLeds(); // Parpadean todos los LEDs
        } else if (data == 'b') {
            Serial.println("LED 2 Parpadean");
            blinkLed(led2); // Parpadea solo LED 2
        } else if (data == 'c') {
            Serial.println("LED 3 Parpadean");
            blinkLed(led3); // Parpadea solo LED 3
        } else if (data == 'f') {
            Serial.println("All LEDs OFF");
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW); // Apaga todos los LEDs
        }
    }
}

void blinkLed(int ledPin) {
    for (int i = 0; i < 10; i++) { // Parpadea 10 veces
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
    }
}
