# ArqCompFinal
## Para hacer que funcione el código
- as Bat.s -o Bat.o
- as Sem.s -o Sem.o
- as Auto.s -o Auto.o
- as Car.s -o Car.o
- as Cho.s -o Cho.o
- as Ola.s -o Ola.o
- as Pi.s -o Pi.o
- gcc -Wall -lm -lcurl -lwiringPi -o proyecto proyecto.c Sem.o Bat.o Auto.o Car.o Cho.o Ola.o Pi.o
- sudo ./proyecto

## Para Interactuar con el Bot
- El bot le mandará un mensaje para que el usuario elija algún comando disponible del menú.
## Donde Conectar
- Conectar en los piner con la ubicacion: 8,10,12,16,18,22,24,26