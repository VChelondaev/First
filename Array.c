#define _CRT_SECURE_NO_WARRNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <malloc.h>



#define TYPE double
#define BASE 10000000

//TYPE array[BASE] = { 0 };

int main() {


		TYPE sum = 0;
		TYPE* array = (TYPE*)malloc(BASE * sizeof(TYPE));
#pragma acc kernels
	{
		for (int i = 0; i < BASE; i++) {
			array[i] = sin(2 * M_PI * i / BASE);
		}
	}
#pragma acc kernels
	{
		for (int i = 0; i < BASE; i++) {
			sum += array[i];
		}
		printf("%lf", sum);
	}

	

	return 0;
}
