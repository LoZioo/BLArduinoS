#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

using namespace BLArduinoS;
// namespace bl = BLArduinoS;

int main(){
	float *A = full(2, 3);
	float *B = copy(A, 3);
	
	// float *C = append(A, B, 3, 3);

	print(A, 3);

	// printf("----------| A |----------\n");
	// printf("%s\n", toString(A, 3, 3).c_str());

	// printf("----------| B |----------\n");
	// printf("%s\n", toString(B, 3, 2).c_str());

	// printf("----------| v |----------\n");
	// printf("%s\n", toString(v, 3).c_str());

	// matmul(A, B, C, 3, 3, 2);
	// printf("----------| matmul(A, B) |----------\n");
	// printf("%s\n", toString(A, 3, 3).c_str());
	// printf("%s\n", toString(B, 3, 2).c_str());
	// printf("%s\n", toString(C, 3, 2).c_str());

	// matmul(A, new float[3]{ 1, 4, 7 }, v, 3, 3);
	// printf("----------| matmul(A, vec) |----------\n");
	// printf("%s\n", toString(v, 3).c_str());

	// matmul(
	// 	A,
	// 	B,
	// 	new float[4]{
	// 		1, 2,
	// 		3, 4
	// 	},
	// 	C,
	// 	3, 3, 2, 2
	// );

	// printf("----------| matmul(A, B, mat) |----------\n");
	// printf("%s\n", toString(C, 3, 2).c_str());

	return 0;
}
