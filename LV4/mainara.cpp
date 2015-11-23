#include <windows.h>
#include <process.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <time.h>

//#define NTHRD 4
#define N 1000
#define M 1000

float *Matrica = (float *)malloc(N*M*sizeof(float));

int popuni()
{
	int i, j, k;
	float suma = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j < M; j++){
			for (k = 0; k < i; k++){
				suma += k*sin((float)j) - j*cos((float)k);
				//if (i < 2)
				//	printf("%f \t", suma);
			}

			*(Matrica + i*N + j) = suma;
		}
	}
	return 0;
}

int main()
{
	clock_t t1, t2;

	t1 = clock();
	popuni();
	t2 = clock();

	printf("KRAJNJE VRIJEME %d", t2 - t1);
	system("pause");
	return 0;
}
