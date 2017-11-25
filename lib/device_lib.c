#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "device_lib.h"
FILE * device;

/*
	Llama al método para moverse 'spaces' a la izquierda
*/
void move_left(int spaces){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("x%d", spaces);
		fprintf(device, "x%d", spaces);
		fclose(device);
	}
	else{
		printf("File not found\n");
	}
}

/*
	Llama al método para moverse 'spaces' a la derecha
*/
void move_right(int spaces){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("x%d", spaces);
		fprintf(device, "x%d", spaces);
		fclose(device);
	}
	else{
		printf("File not found\n");
	}
}

/*
	Llama al método para moverse 'spaces' hacia arriba
*/
void move_up(int spaces){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("y%d", spaces);
		fprintf(device, "y%d", spaces);
		fclose(device);
	}
	else{
		printf("File not found\n");
	}
}

/*
	Llama al método para moverse 'spaces' hacia abajo
*/
void move_down(int spaces){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("y%d", spaces);
		fprintf(device, "y%d", spaces);
		fclose(device);
	}
	else{
		printf("File not found\n");
	}
}

/*
	Llama al método para mantener presionado el dedo
*/
void down(){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("%c", 'd');
		fprintf(device, "%c", 'd');
		fclose(device);
	}
	else{
		printf("File not found\n");
	}
}

/*
	Llama al método para dar un toque al dispositivo
*/
void touch(){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("%c", 't');
		fprintf(device, "%c", 't');
		fclose(device);
	}
	else{
		printf("File not found\n");
	}
}

/*
	Llama al método para levantar el dedo
*/
void up(){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("%c", 'u');
		fprintf(device, "%c", 'u');
		fclose(device);
	}
	else{
		printf("File not found\n");
	}
}

/*
	Llama al método para establecer el tamaño de los espacios
*/
void size(int spaces){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("S%d", spaces);
		fprintf(device, "S%d", spaces);
		fclose(device);
	}
	else{
		printf("File not found\n");
	}
}

void onLED(int on){
	device = fopen("/dev/arduino0","r+");
	if(device != NULL){
		printf("O%d", on);
		fprintf(device, "O%d", on);
		fclose(device);
	}
	else{
		printf("File not found\n");
	}	
}