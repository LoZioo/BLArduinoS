#include <stdio.h>

#include "BLArduinoS/BLArduinoS.h"
#include "BLArduinoS/BLArduinoS.cpp"

#define A_DIM 3
float A[] = {
	1, 2, 3,
	4, 5, 6,
	7, 8, 9
};

#define B_DIM 3
float B[] = {
	1, 2, 3,
	4, 5, 6,
	7, 8, 9
};

#define C_DIM 3
float C[C_DIM * C_DIM];

#define v_DIM 3
float v[] = { 1, 4, 7 };

#define u_DIM 3
float u[u_DIM];

int main(){
	printf("----------| A |----------\n");
	printf("%s\n", BLAS::toString(A, A_DIM, A_DIM).c_str());

	printf("----------| B |----------\n");
	printf("%s\n", BLAS::toString(B, B_DIM, B_DIM).c_str());

	printf("----------| v |----------\n");
	printf("%s\n", BLAS::toString(v, v_DIM).c_str());

	printf("----------| matmul(A, B) |----------\n");
	BLAS::matmul(A, B, C, A_DIM, A_DIM, B_DIM);
	printf("%s\n", BLAS::toString(C, C_DIM, C_DIM).c_str());

	// https://matrixcalc.org/#%7B%7B1,2,3%7D,%7B4,5,6%7D,%7B7,8,9%7D%7D*%7B%7B1%7D,%7B4%7D,%7B7%7D%7D 
	// printf("----------| matmul(A, v) |----------\n");
	// BLAS::matmul(A, v, u, 3, 3, 1);
	// printf("%s\n", BLAS::toString(C, v_DIM).c_str());

	return 0;
}
