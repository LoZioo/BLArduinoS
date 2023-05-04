#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;

int main(){
	float *A = full(2, 2, 2);
	A[mtx(0,0,2)] = 10;

	print(A, 2, 2);
	printf("%f\n", det2(A));

	destroyAll();
	return 0;
}
