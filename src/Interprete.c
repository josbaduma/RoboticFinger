#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "device_lib.h"

int largoPantalla=0;
int VerificarNumero (char* numero){
  int largo = strlen(numero);
  int error=0;
  for (int i=0;i<largo;i++){
      if(!isdigit(numero[i])){
        error=1;
        break;
      }      
  }

return error;
}
void AnalizaInstrucciones(char* nemonico, char* numero){
  int numeroPasos=0;
  if (strcmp(nemonico,"moveleft") == 0){
      if (!VerificarNumero(numero)) { // si no hay letras en el valor 
        numeroPasos= atoi(numero);
        if(numeroPasos<181){
        	move_left(numeroPasos);
        }
        else
        	printf("La cantidad de movimiento excede el movimiento máximo\n");
        
      }
      else{
        printf("El valor movimiento no es válido\n");
      } 
  }
  else if (strcmp(nemonico,"moveright") == 0){
      if (!VerificarNumero(numero)) { // si no hay letras en el valor 
        numeroPasos= atoi(numero);
        if(numeroPasos<181){
        	move_right(numeroPasos);
        }
        else
        	printf("La cantidad de movimiento excede el movimiento máximo\n");
      }
      else{
        printf("El valor movimiento no es válido\n");
      } 
  }
  else if (strcmp(nemonico,"moveup") == 0){
      if (!VerificarNumero(numero)) { // si no hay letras en el valor 
        numeroPasos= atoi(numero);
        if(numeroPasos<181){
        	move_up(numeroPasos);
        }
        else
        	printf("La cantidad de movimiento excede el movimiento máximo\n");
      }
      else{
        printf("El valor movimiento no es válido\n");
      } 
  }
  else if (strcmp(nemonico,"movedown") == 0){
      if (!VerificarNumero(numero)) { // si no hay letras en el valor 
        numeroPasos= atoi(numero);
        if(numeroPasos<181){
        	move_down(numeroPasos);
        }
        else
        	printf("La cantidad de movimiento excede el movimiento máximo\n");
      }
      else{
        printf("El valor movimiento no es válido\n");
      } 
  }
  else if (strcmp(nemonico,"push") == 0){
      if (!VerificarNumero(numero)) { // si no hay letras en el valor 
        numeroPasos= atoi(numero);
        if(numeroPasos<10){
        	down();
        	sleep(numeroPasos);
        	up();
        }
        else
        	printf("La cantidad de movimiento excede el movimiento máximo\n");
      }
      else{
        printf("El valor movimiento no es válido\n");
      } 
  }
  else if (strcmp(nemonico,"down") == 0){
  		if (strcmp(numero,"defalut") == 0){
			down();
  		}
  		else 
  			printf("Error en la instrucción\n");

  }
  else if (strcmp(nemonico,"up") == 0){
  		if (strcmp(numero,"defalut") == 0){
			up();
  		}
  		else
  			 printf("Error en la instrucción \n");
  		}
  	
  else if (strcmp(nemonico,"touch") == 0){
  		if (strcmp(numero,"defalut") == 0){
			touch(); 
  		}
  		else 
  			printf("Error en la instrucción\n");
  }
  else if (strcmp(nemonico,"onled") == 0){
      if (!VerificarNumero(numero)) { // si no hay letras en el valor 
        numeroPasos= atoi(numero);
        if(numeroPasos<10){
        	onLED(numeroPasos);
        }
        else
        	printf("La cantidad de movimiento excede el movimiento máximo\n");
      }
      else{
        printf("El valor movimiento no es válido\n");
      } 
  }
  else if (strcmp(nemonico,"size") == 0){
      if (!VerificarNumero(numero)) { // si no hay letras en el valor 
        largoPantalla= atoi(numero);
        if(largoPantalla<4){
        	printf("Estableciendo el valor de la pantalla %d \n",largoPantalla);
        }
        else
        	printf("La cantidad de movimiento excede el movimiento máximo\n");
      }
      else{
        printf("El valor movimiento no es válido\n");
      } 
  }
  else{
    printf("Error, no existe la instrucción ingresada\n");
  }

}
void SeparaTokens (char instruccion[] ){
    
    // esta parte del código se basó en un ejemplo el cual se puede encontrar en la siguiente página.
    // esta sección del código se baso en fresh2refresh, el cual se puede encontrar en https://fresh2refresh.com/c-programming/c-strings/
    
    char *nemonic="defalut";
    char *valor="defalut";
    char *error="Ok";
    char *p;
    //printf ("String  \"%s\" is split into tokens:\n",instruccion);
    p = strtok (instruccion," ");
    int indice=0;
    while (p!= NULL) // mintra que haya tokens
    {
      if (indice>1){ // si hay más parámetros de la  cuenta 
        error="Error";
        break;
      }
      else if (indice==0) // si es el nombre de la instrucción
        nemonic=p;

      else // si es el numero de pasos que se debe de mover
        valor=p;

      //final[indice]=p; 
      //printf ("%s\n",final[indice]);
      p = strtok (NULL, " "); // asigna el token separador
      indice++;
    }
    if (strcmp(error,"Error") == 0) // verifica que no se introduzcan datos de más.
      printf("La instrucción ingresada no es correcta \n");
    else{
      AnalizaInstrucciones(nemonic,valor);
    }

}
int main ()
{

  char cadena[50]="Ok";
  char *instruccion;
  //printf("Por favor ingrese la instrución a ejecutarse: \n");
  //fgets (cadena, 50, stdin);
  //scanf("%50[^\n]",cadena);
  //printf("el valor es: %s\n",cadena );
  while(strcmp(cadena,"exit") != 0){
    
    printf("Ingrese la siguiente instrucción a ejecutarse: \n");
    //scanf("%s",cadena);

    fgets (cadena,50,stdin);
    //cadena=strtok(cadena, "\n");
    instruccion=strtok(cadena, "\n"); // Le quita el enter a la instrucción
    if (strcmp(cadena,"exit")!=0) // verifica si la instrucción ingresada es el final del programa
        SeparaTokens(cadena); // inicia la separación de tokens para el analisis correspondiente
    else // si no es que digito exit por lo que se debe de finalizar el proceso
        break;

  }
  printf("Programa terminado, Gracias\n");
  
  return 0;
}