#include "BLArduinoS.h"

void BLAS::matmul(const float *A, const float *B, float *R, uint8_t m, uint8_t n, uint8_t p = 1){
	for(uint8_t i=0; i<m; i++){
		for(uint8_t j=0; j<p; j++){
			R[mtx(i,j,p)] = 0;

			for(uint8_t k=0; k<n; k++)
				R[mtx(i,j,p)] += A[mtx(i,k,n)] * B[mtx(k,j,p)];
		}
	}
}

void BLAS::matmul(const float *A, const float *B, const float *C, float *R, uint8_t m, uint8_t n, uint8_t p, uint8_t q = 1){
	float *AB = new float[m * p];

	BLAS::matmul(A, B, AB, m, n, p);
	BLAS::matmul(AB, C, R, m, p, q);

	delete[] AB;
}

template <class T>
T BLAS::map(T x, T in_min, T in_max, T out_min, T out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

String BLAS::toString(const float *A, uint8_t m, uint8_t n = 1){
	String ret = "";
	char buf[14];

	for(uint8_t i=0; i<m; i++){
		ret += "[ ";

		for(uint8_t j=0; j<n; j++){
			dtostrf(A[mtx(i,j,n)], 13, 7, buf);

			ret += buf;
			ret += '\t';
		}

		ret += "]\n";
	}

	return ret;
}
