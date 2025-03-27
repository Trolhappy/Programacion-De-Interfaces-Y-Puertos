#include <Servo.h>


Servo miServo; // Crea un objeto Servo


int servoPin = 9; // Pin conectado al microservo


void setup() {
miServo.attach(servoPin); // Asocia el objeto Servo al pin digital
}


void loop() {

// Mueve el servo a 0 grados 
miServo.write(0);
delay(1000); // Espera 1 segundo


// Mueve el servo a 90 grados 
miServo.write(90);
delay(1000); // Espera 1 segundo

// Mueve el servo a 180 grados 
miServo.write(180);
delay(1000); // Espera 1 segundo


// Mueve el servo a 45 grados
miServo.write(45);
delay(1000); // Espera 1 segundo


// Mueve el servo a 135 grados 
miServo.write(135);
delay(1000); // Espera 1 segundo


// Mueve el servo a 0 grados
miServo.write(0);
delay(1000); // Espera 1 segundo
}
