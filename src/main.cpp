#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;

int main(){
	float *A = ones(3, 2);
	A[mtx(0,0,2)] = 10;
	A[mtx(2,1,2)] = 7;
	A[mtx(1,1,2)] = 5;

	print(A, 3, 2);
	print(transponse(A, 3, 2), 2, 3);

	// printf("%f\n", det3(A));

	destroyAll();
}
