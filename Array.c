#define _CRT_SECURE_NO_WARRNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <malloc.h>
#include <omp.h>

#define TYPE double

#ifdef FLOAT
#define TYPE float
#endif // FLOAT

#define BASE 10000000

//TYPE array[BASE] = { 0 };

int main() {

	
	TYPE sum = 0;
	TYPE* arr = (TYPE*)malloc(BASE * sizeof(TYPE));
	double wtime;
	#pragma acc data create(arr[:N])
	#pragma acc kernels
	{		
		double wtime_start = omp_get_wtime();
		for (int i = 0; i < BASE; i++) {
			arr[i] = sin(2 * M_PI * i / BASE);
		}
		double wtime_end = omp_get_wtime();
		wtime = wtime_end - wtime_start;
		
	}
	printf("to fill: %lf\n", wtime);
	#pragma acc kernels
	{
		double wtime_start = omp_get_wtime();
		for (int i = 0; i < BASE; i++) {
			sum += arr[i];
		}
		double wtime_end = omp_get_wtime();
		wtime = wtime_end - wtime_start;
		
	}
	printf("to sum: %lf\n", wtime);
	
	printf("%lf\n", sum);

	return 0;
}
