#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/tiempo.h"

void shell(int *numeros,int n);

int main(int a,char *args[]){
    
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
    int *numeros,n,i;
	
    numeros = (int*)malloc(10000000*sizeof(int));
    
    //Limite de numeros
    n = atoi(args[1]);
    
    //Leer n numeros del archivo
    for(i = 0;i < n;i++){
          scanf("%d",&numeros[i]);
          //printf("%d ",numeros[i]);      
    }
    
    uswtime(&utime0, &stime0, &wtime0);
    //Ordenamiento Shell
    shell(numeros,n);

    printf("====================NUMEROS=================\n");
    //Imprimir Arreglo
    for(i = 0;i < n;i++)
          printf("%d\n",numeros[i]);
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
    
    
    return 0;    
}

void shell(int *numeros,int n){
     int i,j,k,v;
     k = n/2;
     
     while(k >= 1){
             for(i = k;i < n;i++){
                v = numeros[i];
                j = i - k;
                while(j >= 0 && numeros[j] > v){
                        numeros[j + k] = numeros[j];
                        j -= k;
                }
                numeros[j + k] = v; 
             }
             k/=2; 
     }
}
