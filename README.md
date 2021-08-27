##### El sistema cuenta con un sensor HX711, un LCD de 16x2 y un Arduino UNO . 
El proyecto en GitHub cuenta con un archivo de calibracion y uno del sistema listo para funcionar. 

El archivo de calibracion se utiliza para generar el factor de calibracion. Este factor se inicializa en 374.8 (puede ver la liberia HX711 ). Para calibrar inicialmente no debe haber peso en la balanza y seguir los pasos que se dan por el terminar virtual del Arduino IDE. Cuando se pida, se pone un peso conocido y esto dara un peso que se acerca al peso real, entonces poniendo el signo de + o - en el terminal vamos cambiando el factor de calibracion en 0.05 hasta que el peso real sea igual al medido. Terminado esto , tomamos el valor final del factor de calibracion y lo ponemos en el programa del sistema en la funcion **balanza.set_scale**.

El programa final del sistema dara una serie de instrucciones y dira cuando esta listo para medir . Se tomaran 10 mediciones en un tiempo de 1 segundo y se visualizara en el LCD (valor en gramos y libras). Se volvera a repetir el proceso cada 10 segundos. 

Se debe incluir las librerias **HX711.h** y **LiquidCrystal.h**
