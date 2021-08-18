#include "HX711.h"
 
// Pin de datos y de reloj
byte pinData = 3;
byte pinClk = 2;
 int z=1; // condicion de lectura de peso 
 int peso_cal=0;
 int r=1;
 
HX711 bascula;
 
// Parámetro para calibrar el peso y el sensor
float factor_calibracion = 374.8; //Este valor del factor de calibración funciona para mi. El tuyo probablemente será diferente.
 
void setup() {
  Serial.begin(9600);
  Serial.println("HX711 programa de calibracion");
  Serial.println("Quita cualquier peso de la bascula");
  Serial.println("Una vez empiece a mostrar informacion de medidas, coloca un peso conocido encima de la bascula");
  
 
  // Iniciar sensor
  bascula.begin(A1, A0);
 
  // Aplicar la calibración
  bascula.set_scale();
  // Iniciar la tara
  // No tiene que haber nada sobre el peso
  bascula.tare();
 
  // Obtener una lectura de referencia
  long zero_factor = bascula.read_average();
  // Mostrar la primera desviación
  Serial.print("Zero factor: ");
  Serial.println(zero_factor);
  delay (1000);
  Serial.print("Introduzca el peso de calibracion ");

  while (z==1)
  while(Serial.available())
  {
   peso_cal=Serial.parseInt();
  z=0;
  }
  Serial.print ("Peso introducido  ");
  Serial.println (peso_cal);
  delay(3000);
}
 
void loop() {

 while (r==1)
 {
  // Aplicar calibración
  bascula.set_scale(factor_calibracion);
 
  // Mostrar la información para ajustar el factor de calibración
  Serial.print("Leyendo: ");
  float peso=bascula.get_units();
  Serial.print(peso, 1);
  Serial.print(" g ");
  Serial.print(peso_cal);
  Serial.print(" g ");
  Serial.print(" factor_calibracion: ");
  Serial.print(factor_calibracion);
  Serial.println();
 
  // Obtener información desde el monitor serie
  if ((peso+0.001*peso_cal)<= peso_cal || (peso-0.001*peso_cal)>= peso_cal)
  {
     if (peso_cal<= peso)
        {
          factor_calibracion += 0.2;
        }
     if (peso_cal>= peso)
        {
          factor_calibracion -= 0.2;
        }
  }
  else 
  {
    r=0;
    Serial.println ("Calibracion terminada ...");
    Serial.print ("Factor de calibracion: ");
    Serial.println (factor_calibracion);
  }
  delay (5000);
 }
//  if (Serial.available())
//  {
//    char temp = Serial.read();
//    if (temp == '+')
//      factor_calibracion += 0.05;
//    else if (temp == '-')
//      factor_calibracion -= 0.05;
//  }
}
