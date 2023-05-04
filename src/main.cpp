#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;

int main(){
	float *A = full(2, 3, 3);
	A[mtx(0,0,3)] = 10;
	A[mtx(2,1,3)] = 7;
	A[mtx(1,2,3)] = 5;

	print(A, 3, 3);
	printf("%f\n", det3(A));

	destroyAll();
}
