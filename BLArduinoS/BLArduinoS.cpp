#include "BLArduinoS.h"

template<class T>
T map(T x, T in_min, T in_max, T out_min, T out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

namespace BLArduinoS {
	void destroy(float *A){
		delete[] A;
	}

	float* array(uint8_t m, uint8_t n = 1){
		return new float[m*n];
	}

	float* full(float val, uint8_t m, uint8_t n = 1){
		uint8_t dim = m*n;
		float *arr = new float[dim];

		for(uint8_t i=0; i<dim; i++)
			arr[i] = val;

		return arr;
	}

	float* zeros(uint8_t m, uint8_t n = 1){
		return full(0, m, n);
	}

	float* ones(uint8_t m, uint8_t n = 1){
		return full(1, m, n);
	}

	float* append(float *u, float *v, uint8_t m, uint8_t n){
		float *arr = new float[m+n];

		for(uint8_t i=0; i<m; i++)
			arr[i] = u[i];

		for(uint8_t i=0; i<n; i++)
			arr[m+i] = v[i];

		return arr;
	}

	float* copy(float *v, uint8_t m, uint8_t n = 1){
		uint8_t dim = m*n;
		float *arr = new float[dim];

		std::memcpy(arr, v, dim * sizeof(float));
		return arr;
	}

	float* matmul(float *A, float *B, uint8_t m, uint8_t n, uint8_t p = 1){
		float *R = new float[m*p];

		for(uint8_t i=0; i<m; i++){
			for(uint8_t j=0; j<p; j++){
				R[mtx(i,j,p)] = 0;

				for(uint8_t k=0; k<n; k++)
					R[mtx(i,j,p)] += A[mtx(i,k,n)] * B[mtx(k,j,p)];
			}
		}

		return R;
	}

	float* matmul(float *A, float *B, float *C, uint8_t m, uint8_t n, uint8_t p, uint8_t q = 1){
		float *R = new float[m*q];
		float *AB = new float[m*p];

		matmul(A, B, AB, m, n, p);
		matmul(AB, C, R, m, p, q);

		destroy(AB);
		return R;
	}

	String toString(float *A, uint8_t m, uint8_t n = 1, uint8_t width = 13, uint8_t precision = 7){
		String ret = "";
		char buf[14];

		for(uint8_t i=0; i<m; i++){
			ret += "[ ";

			for(uint8_t j=0; j<n; j++){
				dtostrf(A[mtx(i,j,n)], width, precision, buf);

				ret += buf;
				ret += '\t';
			}

			ret += "]\n";
		}

		return ret;
	}

	void print(float *A, uint8_t m, uint8_t n = 1, uint8_t width = 13, uint8_t precision = 7){
		String str = toString(A, m, n, width, precision);
		
		#ifdef ARDUINO
			Serial.println(str);

		#else
			printf("%s\n", str.c_str());

		#endif
	}
}
