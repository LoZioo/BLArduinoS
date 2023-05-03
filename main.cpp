#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;

int main(){
	float *A = full(2, 2, 3);
	float *B = full(6, 2, 3);
	float *C = sum(A, B, 2, 3);

	print(A, 2, 3);
	print(B, 2, 3);
	print(C, 2, 3);

	return 0;
}
