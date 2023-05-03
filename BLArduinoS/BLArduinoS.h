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

	#include <cstring>
	#include <string>

	#define String std::string

	#define dtostrf(value, width, precision, output) \
		sprintf(output, "%*.*f", width, precision, value)

	#define Serial.println(str) (printf("%s\n", str))

#endif

/// @brief Range remap for any supported type.
template<class T>
T map(T x, T in_min, T in_max, T out_min, T out_max);

/// @brief Value constrain.
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

/// @brief Convert 2D matrix indexing to 1D array indexing.
#define mtx(i,j,cols) (i*cols+j)

// IMPORTANT: YOU MUST MANUALLY FREE YOUR ALLOCATED MEMORY ON YOUR UNUSED POINTERS BY CALLING THE destroy() FUNCTION!
namespace BLArduinoS {
	/// @brief Free the allocated memory.
	void destroy(float *A);

	/// @return Uninitialized array.
	float* array(uint8_t m, uint8_t n);

	/// @return Array full of the specified vals.
	float* full(float val, uint8_t m, uint8_t n);

	/// @return Array full of zeros.
	float* zeros(uint8_t m, uint8_t n);
	
	/// @return Array full of ones.
	float* ones(uint8_t m, uint8_t n);

	/**
	 * @brief Append v to u.
	 * @param u array long m.
	 * @param v array long n.
	 * @return A pointer to the newly created array.
	 */
	float* append(float *u, float *v, uint8_t m, uint8_t n);

	/// @return A copy of the array.
	float* copy(float *v, uint8_t m, uint8_t n);

	/**
	 * @brief Matrix multiplication R = AB.
	 * @param A m x n matrix.
	 * @param B n x p matrix.
	 * @param R m x p matrix.
	 * @return A pointer to the result.
	 */
	float* matmul(float *A, float *B, uint8_t m, uint8_t n, uint8_t p);

	/**
	 * @brief Matrix multiplication R = ABC.
	 * @param A m x n matrix.
	 * @param B n x p matrix.
	 * @param C p x q matrix.
	 * @param R m x q matrix.
	 * @return A pointer to the result.
	 */
	float* matmul(float *A, float *B, float *C, uint8_t m, uint8_t n, uint8_t p, uint8_t q);

	/// @brief Get a string representation of your array or matrix.
	String toString(float *A, uint8_t m, uint8_t n, uint8_t width, uint8_t precision);

	/// @brief Print a string representation of your array or matrix.
	void print(float *A, uint8_t m, uint8_t n, uint8_t width, uint8_t precision);
}
