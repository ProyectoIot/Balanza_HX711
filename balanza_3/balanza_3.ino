#include "HX711.h"

#include <LiquidCrystal.h> // Add LiquidCrystal library
LiquidCrystal lcd(6, 7, 2, 3, 4, 5); // creation of object LCD

const int DOUT=A1;
const int CLK=A0;

float peso=0;
float peso_total=0;

HX711 balanza;

void setup()
{
lcd.begin(16,2); // initialization of LCD object
Serial.begin(9600);
balanza.begin(DOUT, CLK);
lcd.clear(); // Erase screen
lcd.setCursor(1,0);

Serial.println(balanza.read());
lcd.print("BALANZA");
lcd.setCursor(0,1);
lcd.print("Destarando...");
balanza.set_scale(371.55); // Establecemos la escala
delay(10);
balanza.tare();  //El peso actual es considerado Tara.
lcd.clear(); // Erase screen
lcd.setCursor(1,0);
lcd.print("Listo para pesar");
delay(1000); 

}

void loop()
{
lcd.clear();
lcd.setCursor(1,0);
lcd.print("Peso: ");
lcd.setCursor(9,0);
peso_total=0;
 for (int i=0;i<10;i++)
 {
  peso=balanza.get_units();
  peso_total+=peso;
  delay(500);
  Serial.println(i);
 }
 peso_total=peso_total/10.0;
 Serial.println(peso_total);
if (peso_total<0){ 
  // eliminar el error inicial sin peso. . .
  peso_total=0;
  }
lcd.print(peso_total);
lcd.print(" g");
lcd.setCursor(9,1);
lcd.print(peso_total/460.0);
lcd.print(" lbs");

delay(5000); 


}
