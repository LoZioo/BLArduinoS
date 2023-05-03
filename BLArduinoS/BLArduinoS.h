/**
 * @file BLArduinoS.h
 * @author Davide Scalisi
 * @brief BLAS (Basic Linear Algebra Subroutines) minimal implementation for embedded devices.
 * @version 0.1
 * @date 2023-04-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ARDUINO
	#include <stdio.h>
	#include <stdlib.h>
	#include <stdint.h>
	#include <string>

	#define String std::string
	#define dtostrf(value, width, precision, output) \
		sprintf(output, "%*.*f", width, precision, value)

#endif

/// @brief Range remap for any supported type.
template <class T>
T map(T x, T in_min, T in_max, T out_min, T out_max);

/// @brief Value constrain.
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

/// @brief Convert 2D matrix indexing to 1D array indexing.
#define mtx(i,j,cols) (i*cols+j)

namespace BLArduinoS {
	/**
	 * @brief Matrix multiplication R = AB.
	 * @param A m x n matrix.
	 * @param B n x p matrix.
	 * @param R m x p matrix.
	 */
	void matmul(const float *A, const float *B, float *R, uint8_t m, uint8_t n, uint8_t p);

	/**
	 * @brief Matrix multiplication R = ABC.
	 * @param A m x n matrix.
	 * @param B n x p matrix.
	 * @param C p x q matrix.
	 * @param R m x q matrix.
	 */
	void matmul(const float *A, const float *B, const float *C, float *R, uint8_t m, uint8_t n, uint8_t p, uint8_t q);

	/// @brief Get a string representation of your vector or matrix.
	String toString(const float *A, uint8_t m, uint8_t n);
}
