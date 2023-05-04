#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;

int main(){
	float *A = ones(2, 2);
	A[mtx(0,0,2)] = 10;
	A[mtx(1,1,2)] = 5;

	print(A, 2, 2);
	printf("%f\n", algebric_complement2(A, 1, 1));

	destroyAll();
}
