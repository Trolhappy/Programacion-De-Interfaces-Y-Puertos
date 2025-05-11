//Jair Alejandro Calderon Maldonado, Isaac Catelan Gamoneda, Cristian Castro Marquez, Jonathan Valentin Lopez Camacho, Joshua Romany Ramirez Bustos
const int ledPin = 13; // Pin del LED 
int ledState = LOW; // Estado del LED 
unsigned long previousMillis = 0; // Almacena el tiempo anterior 
const long interval = 1000; // Intervalo de tiempo en milisegundos 
void setup() { 
 Serial.begin(9600); // Inicializa la comunicación serial 
 pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida 
} 
void loop() { 
 unsigned long currentMillis = millis(); // Obtiene el tiempo actual 
 // Verifica si ha pasado el intervalo de tiempo 
 if (currentMillis - previousMillis >= interval) { 
 previousMillis = currentMillis; // Actualiza el tiempo anterior 
 int sensorValue = analogRead(A0); // Lee el valor del sensor 
 Serial.println(sensorValue); // Envía el valor por el puerto serie 
 } 
 // Verifica si hay datos disponibles en el puerto serie 
 if (Serial.available() > 0) { 
 char command = Serial.read(); // Lee el comando recibido 
 if (command == '1') { 
 ledState = HIGH; // Enciende el LED 
 } else if (command == '0') { 
 ledState = LOW; // Apaga el LED 
 } 
 digitalWrite(ledPin, ledState); // Actualiza el estado del LED 
 } 
} 