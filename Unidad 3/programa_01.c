
///Jair Alejandro Calderon Maldonado, Isaac Castelan Gamoneda, Cristian Castro Marquez, Jonathan Valentin Lopez Camacho, Joshua Romany Ramirez Bustos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main()
{
  int serial_port = open("/dev/ttyACM0", O_RDWR); // Abre el puerto serie
  if (serial_port < 0)
  {
    perror("Error al abrir el puerto serie");
    return 1;
  }

  struct termios tty;
  memset(&tty, 0, sizeof(tty));
  if (tcgetattr(serial_port, &tty) != 0)
  {
    perror("Error al obtener atributos del puerto serie");
    return 1;
  }

  tty.c_cflag = CS8 | CREAD | CLOCAL; // Configura el puerto serie
  tty.c_cc[VMIN] = 1;                 // Lee al menos 1 carácter
  tty.c_cc[VTIME] = 5;                // Espera hasta 0.5 segundos para la entrada

  if (tcsetattr(serial_port, TCSANOW, &tty) != 0)
  {
    perror("Error al establecer atributos del puerto serie");
    return 1;
  }

  char buffer[256];
  int bytes_read;
  int sensorValue;

  while (1)
  {
    bytes_read = read(serial_port, buffer, sizeof(buffer));
    if (bytes_read > 0)
    {
      buffer[bytes_read] = '\0';  // Termina la cadena
      sensorValue = atoi(buffer); // Convierte la cadena a entero
      printf("Valor del sensor: %d\n", sensorValue);

      if (sensorValue > 500)
      {                               // Umbral para encender el LED
        write(serial_port, "1\n", 2); // Envía "1" para encender el LED
      }
      else
      {
        write(serial_port, "0\n", 2); // Envía "0" para apagar el LED
      }
    }
    usleep(100000); // Espera 0.1 segundos
  }
  close(serial_port);
  return 0;
}