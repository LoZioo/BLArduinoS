#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;

int main(){
	printf("used: %d\n", getUsedMemory());

	float *A = full(2, 3, 3);
	printf("used: %d\n", getUsedMemory());

	float *B = full(6, 3, 3);
	printf("used: %d\n", getUsedMemory());

	float *C = full(4, 3, 3);
	printf("used: %d\n", getUsedMemory());

	float *D = matmul(A, B, C, 2, 2, 2, 2);

	print(A, 2, 2);
	print(B, 2, 2);
	print(C, 2, 2);
	print(D, 2, 2);

	destroyAll();
	printf("used: %d\n", getUsedMemory());

	return 0;
}
