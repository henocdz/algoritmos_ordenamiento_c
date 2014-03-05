#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/tiempo.h"

/*	Autor: Ivan Acosta
	Version: 1.0	*/

typedef struct Nodo{
        int numero;
        struct Nodo *izq,*der;
}Nodo;

void inOrden(Nodo *arbol);
void inserta(Nodo** arbol,int numero);
Nodo* min(Nodo *raiz);
Nodo *sucesor(Nodo *cur,Nodo *raiz);

int main(int a,char* args[]){
    
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
    int *numeros,n,i;
	Nodo *arbol;
	
	uswtime(&utime0, &stime0, &wtime0);
	
    numeros = (int*)malloc(10000000*sizeof(int));
	arbol = NULL;
	
    
    //Limite de numeros
    n = atoi(args[1]);
    
    //Leer n numeros del archivo
    for(i = 0;i < n;i++){
          scanf("%d",&numeros[i]);
          //printf("%d ",numeros[i]);      
    }
	//putchar('\n');
	//Implementacion del Arbol Binario
	for(i = 0;i < n;i++){
		inserta(&arbol,numeros[i]);
	}//Fin For
	
	printf("====================NUMEROS=================\n");
	//Recorremos el Arbol InOrden para obtener los Numero Ordenados (Imprime)
	inOrden(arbol);
	printf("!===================NUMEROS=================!\n");
	
	uswtime(&utime1, &stime1, &wtime1);
    

	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************



    return 1;    
}

void inserta(Nodo** arbol,int numero){
	while(1){
		if(*arbol == NULL){
			*arbol = (Nodo*)malloc(sizeof(Nodo));
			(*arbol)->numero = numero;
			(*arbol)->der = NULL;
			(*arbol)->izq = NULL;
			break;
		}else{
			//Si el Numero es Mayor voy a la derecha
			if(numero > (*arbol)->numero){
				arbol = &(*arbol)->der;
				continue;
			}
			//Si el Numero es Menor voy a la izquierda
			else if(numero < (*arbol)->numero){
				arbol = &(*arbol)->izq;
				continue;
			}
			//Si el Numero es Igual salgo del Ciclo
			else{
				break;
			}
		}
	}
}

void inOrden(Nodo *arbol){
	if(!arbol) { return; }
	Nodo *cur = min(arbol);
	while(cur) {
		printf("%d\n",cur->numero);
		cur = sucesor(cur,arbol);
	}
	return;
}

Nodo* min(Nodo *raiz) {
	if(!raiz) { return raiz;}
	while(raiz->izq) {
		raiz = raiz->izq;
	}
	return raiz;
}

Nodo* sucesor(Nodo *cur,Nodo *raiz) {
	if(!cur) { return cur;}
	if(cur->der){
		return min(cur->der);
	}
	Nodo* sucesor = 0;
	while(raiz && raiz != cur) {
		if(cur->numero < raiz->numero) {
			sucesor = raiz;
			raiz = raiz->izq;
		} else {
			raiz = raiz->der;
		}
	}
	return sucesor;
}
