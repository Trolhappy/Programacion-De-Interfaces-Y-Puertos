#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
lcd.begin(16, 2); // Inicializa la pantalla LCD (16 columnas, 2 filas)
lcd.print("Hola, mundo!"); // Muestra un mensaje en la pantalla
lcd.setCursor(0, 1); // Coloca el cursor en la segunda fila
lcd.print("LCD directo");
}
void loop() {
// No se hace nada en el bucle principal
}