//MULTITHREADING 'N' SHIT
#define _MT
#include <windows.h>
#include <process.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define NTHRD 4
#define N 1000
#define M 1000

float *Matrica = (float *)malloc(N * M * sizeof(float));
HANDLE hThread[NTHRD];
long ids[NTHRD];


//Funkcija niti
DWORD WINAPI popuni(VOID *p)
{
	int i, j, k;
	float suma = 0;
	int *id = (int *)p;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			for (k = 0; k < i; k++){
				suma += k*sin((float)j) - j*cos((float)k);
			}
			*(Matrica + i*N + j) = suma;

		}
	}
	return 0;
}

int main(){
	int i;
	clock_t t1, t2;
	t1 = clock();
	for (i = 0; i<NTHRD; i++)
	{
		ids[i] = i;
		hThread[i] = CreateThread(NULL, 0, popuni, &ids[i], 0, NULL);
	}
	WaitForMultipleObjects(NTHRD, hThread, TRUE, INFINITE);

	t2 = clock();
	printf("Proteklo vrijeme: %d", t2 - t1);
	getchar();
	free(Matrica);
}