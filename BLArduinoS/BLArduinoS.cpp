#include "BLArduinoS.h"

void BLAS::matmul(const float *A, const float *B, float *R, uint8_t m, uint8_t n, uint8_t p){
	const float (*A_mtx)[n] = (const float (*)[n]) A;
	const float (*B_mtx)[p] = (const float (*)[p]) B;
	float (*R_mtx)[p] = (float (*)[p]) R;

	for(uint8_t i=0; i<m; i++){
		for(uint8_t j=0; j<p; j++){
			R_mtx[i][j] = 0.0;

			for(uint8_t k=0; k<n; k++)
				R_mtx[i][j] += A_mtx[i][k] * B_mtx[k][j];
		}
	}
}

void BLAS::matmul(const float *A, const float *B, const float *C, float *R, uint8_t m, uint8_t n, uint8_t p, uint8_t q){
	float *AB = new float[m * p];

	BLAS::matmul(A, B, AB, m, n, p);
	BLAS::matmul(AB, C, R, m, p, q);

	delete[] AB;
}

template <class T>
T BLAS::map(T x, T in_min, T in_max, T out_min, T out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

String BLAS::toString(const float *A, uint8_t m, uint8_t n){
	const float (*A_mtx)[n] = (const float (*)[n]) A;
	char buf[14];
	String ret = "";

	for(uint8_t i=0; i<m; i++){
		ret += "[ ";

		for(uint8_t j=0; j<n; j++){
			// dtostrf(A_mtx[i][j], 13, 7, buf);
			sprintf(buf, "%7f", A_mtx[i][j]);

			ret += buf;
			ret += '\t';
		}

		ret += "]\n";
	}

	return ret;
}
