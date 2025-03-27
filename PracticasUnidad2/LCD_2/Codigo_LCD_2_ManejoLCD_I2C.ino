#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Inicializa la pantalla LCD I2C
void setup() {
lcd.init(); // Inicializa la pantalla LCD
lcd.backlight(); // Enciende la retroiluminación
lcd.print("Hola, Cristian!"); // Muestra un mensaje en la pantalla
lcd.setCursor(0, 1); // Coloca el cursor en la segunda fila
lcd.print("LCD con I2C");
}
void loop() {
// No se hace nada en el bucle principal
}