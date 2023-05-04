#include <stdio.h>

#include <BLArduinoS.h>
#include <BLArduinoS.cpp>

// using namespace BLArduinoS;
namespace bl = BLArduinoS;

int main(){
	float *A = bl::from(new float[9]{
		10, 1, 1,
		1, 5, 1,
		1, 1, 1,
	}, 9);

	bl::print(A, 3, 3);
	bl::print(bl::inv3(A), 3, 3);

	bl::destroyAll();
}
