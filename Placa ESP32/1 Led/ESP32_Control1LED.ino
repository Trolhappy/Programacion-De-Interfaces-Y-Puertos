 #include <WiFi.h>
 #include <WebServer.h>
 const char* ssid = "UAM-ROBOTICA"; // Reemplaza con tu SSID de Wi-Fi
 const char* password = "m4nt32024uat"; // Reemplaza con tu contraseña de Wi-Fi
 WebServer server(80);
 const int ledPin = 2;
 void handleRoot() {
 String html = "<html><body><h1>Control de LED</h1>";
 html += "<a href='/led/on'><button>Encender LED</button></a><br>";
 html += "<a href='/led/off'><button>Apagar LED</button></a>";
 html += "</body></html>";
 server.send(200, "text/html", html);
 }
 void handleLedOn() {
 digitalWrite(ledPin, HIGH);
 server.send(200, "text/plain", "LED Encendido");
 }
 void handleLedOff() {
 digitalWrite(ledPin, LOW);
 server.send(200, "text/plain", "LED Apagado");
 }
 void setup() {
 pinMode(ledPin, OUTPUT);
 digitalWrite(ledPin, LOW);
 Serial.begin(115200);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(1000);
 Serial.println("Conectando a Wi-Fi...");
 }
 Serial.println("Conectado a Wi-Fi");
 Serial.print("Dirección IP: ");
 Serial.println(WiFi.localIP());
 server.on("/", handleRoot);
 server.on("/led/on", handleLedOn);
 server.on("/led/off", handleLedOff);
 server.begin();
 }
 void loop() {
 server.handleClient();
 } 