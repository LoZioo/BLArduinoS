#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;

int main(){
	float *A = full(2, 2, 3);
	float *B = multiply(2, A, 2, 3);

	print(A, 2, 3);
	print(B, 2, 3);

	return 0;
}
