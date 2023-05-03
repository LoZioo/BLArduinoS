#include <stdio.h>

#include "BLArduinoS/BLArduinoS.h"
#include "BLArduinoS/BLArduinoS.cpp"

float A[] = {
	1, 2, 3,
	4, 5, 6,
	7, 8, 9
};

float B[] = {
	1, 2,
	3, 4,
	5, 6
};

float C[9];

float v[] = { 1, 4, 7 };
float u[3];

int main(){
	printf("----------| A |----------\n");
	printf("%s\n", BLAS::toString(A, 3, 3).c_str());

	printf("----------| B |----------\n");
	printf("%s\n", BLAS::toString(B, 3, 2).c_str());

	printf("----------| v |----------\n");
	printf("%s\n", BLAS::toString(v, 3).c_str());

	printf("----------| matmul(A, B) |----------\n");
	BLAS::matmul(A, B, C, 3, 3, 2);
	printf("%s\n", BLAS::toString(A, 3, 3).c_str());
	printf("%s\n", BLAS::toString(B, 3, 2).c_str());
	printf("%s\n", BLAS::toString(C, 3, 2).c_str());

	printf("----------| matmul(A, v) |----------\n");
	BLAS::matmul(A, v, u, 3, 3);
	printf("%s\n", BLAS::toString(u, 3).c_str());

	return 0;
}
