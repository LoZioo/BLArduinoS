#include "BLArduinoS.h"

template<class T>
T map(T x, T in_min, T in_max, T out_min, T out_max){
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

namespace BLArduinoS {
	float *__ptrs[POINTERS_BUFFER_MAXLEN];
	uint8_t __ptrs_index = 0;
	int16_t __mem_used = 0;

	void __save_ptr(float *ptr, uint8_t len){
		__ptrs[__ptrs_index++] = ptr;
		__mem_used += len;
	}

	int16_t __find_ptr_index(float *ptr){
		bool found = false;
		uint8_t i = 0;

		while(i<__ptrs_index && !found){
			if(__ptrs[i] == ptr)
				found = true;

			i++;
		}

		return found ? i - 1 : -1 ;
	}

	void destroy(float *A, uint8_t m = 0, uint8_t n = 1){
		// Find and unset the specified pointer in the __ptrs_index array.
		// Subsequently calling delete[] on a NULL pointer is safe, whereas
		// calling delete[] on an already deleted pointer is dangerous and
		// could potentially lead to program crashes.

		int16_t ptr_index = __find_ptr_index(A);
		if(ptr_index > 0)
			__ptrs[ptr_index] = NULL;

		delete[] A;
		__mem_used -= m*n;
	}

	void destroyAll(){
		for(uint8_t i=0; i<__ptrs_index; i++)
			delete[] __ptrs[i];

		__ptrs_index = __mem_used = 0;
	}

	uint16_t getUsedMemory(){
		return __mem_used * sizeof(float);
	}

	float* array(uint8_t m, uint8_t n = 1){
		uint8_t dim = m*n;
		float *arr = new float[dim];
		__save_ptr(arr, dim);

		return arr;
	}

	float* full(float val, uint8_t m, uint8_t n = 1){
		uint8_t dim = m*n;
		float *arr = array(dim);

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
		float *arr = array(m+n);

		for(uint8_t i=0; i<m; i++)
			arr[i] = u[i];

		for(uint8_t i=0; i<n; i++)
			arr[m+i] = v[i];

		return arr;
	}

	float* copy(float *v, uint8_t m, uint8_t n = 1){
		uint8_t dim = m*n;
		float *arr = array(dim);

		std::memcpy(arr, v, dim * sizeof(float));
		return arr;
	}

	float* multiply(float k, float *A, uint8_t m, uint8_t n = 1){
		uint8_t dim = m*n;
		float *arr = array(dim);

		for(uint8_t i=0; i<dim; i++)
			arr[i] = k * A[i];

		return arr;
	}

	float* sum(float *A, float *B, uint8_t m, uint8_t n = 1){
		uint8_t dim = m*n;
		float *R = array(dim);

		for(uint8_t i=0; i<dim; i++)
			R[i] = A[i] + B[i];

		return R;
	}

	float* sum(float *A, float *B, float *C, uint8_t m, uint8_t n = 1){
		float *AB = sum(A, B, m, n);
		float *R = sum(AB, C, m, n);

		destroy(AB);
		__mem_used -= m * n - 1;

		return R;
	}

	float* matmul(float *A, float *B, uint8_t m, uint8_t n, uint8_t p = 1){
		float *R = array(m, p);

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
		float *AB = matmul(A, B, m, n, p);
		float *R = matmul(AB, C, m, p, q);

		destroy(AB);
		__mem_used -= m * p - 1;

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
