#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/tiempo.h"

void selection_sort(int *data, int data_len);


int main(int argc,char *argv[]){
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n;
	n = atoi(argv[1]);
	int nums[n], i;

	uswtime(&utime0, &stime0, &wtime0);


	for(i=0; i < n; i++){
		scanf("%d", &nums[i]);
	}

	uswtime(&utime0, &stime0, &wtime0);

	selection_sort(nums, n);

	uswtime(&utime1, &stime1, &wtime1);


	printf("====================NUMEROS=================\n");
	for(i=0;i<n;i++)
		printf("%d\n", nums[i]);
	printf("!===================NUMEROS=================!\n");

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

void selection_sort(int *data, int data_len){
	int k,i,p,temp;
	int n = data_len;
	

	for(k=0;k<n-1;k++){
		p = k;
		for(i=k+1;i<n;i++){
			//printf("%d-", data[i]);
			if(data[i] < data[p]){
				p = i;
			}
		}

		
		temp = data[k];
		data[k] = data[p];
		data[p] = temp;

	}
}
