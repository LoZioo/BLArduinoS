#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;

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

float C[100];
float v[100];

int main(){
	printf("----------| A |----------\n");
	printf("%s\n", toString(A, 3, 3).c_str());

	printf("----------| B |----------\n");
	printf("%s\n", toString(B, 3, 2).c_str());

	printf("----------| v |----------\n");
	printf("%s\n", toString(v, 3).c_str());

	matmul(A, B, C, 3, 3, 2);
	printf("----------| matmul(A, B) |----------\n");
	printf("%s\n", toString(A, 3, 3).c_str());
	printf("%s\n", toString(B, 3, 2).c_str());
	printf("%s\n", toString(C, 3, 2).c_str());

	matmul(A, new float[3]{ 1, 4, 7 }, v, 3, 3);
	printf("----------| matmul(A, vec) |----------\n");
	printf("%s\n", toString(v, 3).c_str());

	matmul(
		A,
		B,
		new float[4]{
			1, 2,
			3, 4
		},
		C,
		3, 3, 2, 2
	);

	printf("----------| matmul(A, B, mat) |----------\n");
	printf("%s\n", toString(C, 3, 2).c_str());

	return 0;
}
