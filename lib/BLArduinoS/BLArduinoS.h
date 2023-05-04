/**
 * @file BLArduinoS.h
 * @author Davide Scalisi
 * @brief Very simple BLAS (Basic Linear Algebra Subroutines) implementation for embedded devices inspired by the numpy library.
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

	/// @brief Value constrain.
	#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))

#endif

// Max number of saved pointers.
#define POINTERS_BUFFER_MAXLEN 50

/// @brief Range remap for any supported type.
template<class T>
T map(T x, T in_min, T in_max, T out_min, T out_max);

/**
 * @brief Modulo operator (https://stackoverflow.com/questions/11720656/modulo-operation-with-negative-numbers).
 * @return a mod b
 */
int mod(int a, int b);

/// @brief Convert 2D matrix indexing to 1D array indexing.
#define mtx(i,j,cols) ((i)*(cols)+(j))

// IMPORTANT: you must manually free the allocated memory on your unused pointers by calling destroy() or destroyAll()!
namespace BLArduinoS {
	// ------------------------------| Internal functions |------------------------------
	extern float *ptrs[];
	extern uint8_t ptrs_index;

	void __save_ptr(float *ptr, uint8_t len);
	int16_t __find_ptr_index(float *ptr);

	// ------------------------------| Memory |------------------------------

	/// @brief Free the allocated memory (m and n are needed just to keep track of the used memory, so  they're optional parameters).
	void destroy(float *A, uint8_t m, uint8_t n);

	/// @brief Free all the allocated memory; all previously saved pointers won't be semantically valid anymore.
	void destroyAll();

	/// @brief Get allocated memory in bytes (destroy() calls do not decrement this unless you specify the matrix dimensions).
	uint16_t getUsedMemory();

	// ------------------------------| Initialization |------------------------------

	/// @return Uninitialized array.
	float* array(uint8_t m, uint8_t n);

	/// @brief Register a new pointer in the internal memory manager.
	float* from(float *A, uint8_t m, uint8_t n);

	/// @return Array full of the specified vals.
	float* full(float val, uint8_t m, uint8_t n);

	/// @return Array full of zeros.
	float* zeros(uint8_t m, uint8_t n);

	/// @return Array full of ones.
	float* ones(uint8_t m, uint8_t n);

	/// @return The identity matrix (n x n).
	float* identity(uint8_t n);

	/**
	 * @brief Append v to u.
	 * @param u array long m.
	 * @param v array long n.
	 * @return A pointer to the newly created array.
	 */
	float* append(float *u, float *v, uint8_t m, uint8_t n);

	/// @return A copy of the array.
	float* copy(float *v, uint8_t m, uint8_t n);

	// ------------------------------| Operators (Scalar and Matrix) |------------------------------

	/**
	 * @brief Scalar multiplication R = kB.
	 * @param A m x n matrix.
	 * @return A pointer to the result (m x n).
	 */
	float* multiply(float k, float *A, uint8_t m, uint8_t n);

	// ------------------------------| Operators (Matrix and Matrix) |------------------------------

	/**
	 * @brief Matrix sum R = A+B.
	 * @param A m x n matrix.
	 * @param B m x n matrix.
	 * @return A pointer to the result (m x n).
	 */
	float* sum(float *A, float *B, uint8_t m, uint8_t n);

	/**
	 * @brief Matrix sum R = A+B+C.
	 * @param A m x n matrix.
	 * @param B m x n matrix.
	 * @param C m x n matrix.
	 * @return A pointer to the result (m x n).
	 */
	float* sum(float *A, float *B, float *C, uint8_t m, uint8_t n);

	/**
	 * @brief Matrix multiplication R = AB.
	 * @param A m x n matrix.
	 * @param B n x p matrix.
	 * @return A pointer to the result (m x p).
	 */
	float* matmul(float *A, float *B, uint8_t m, uint8_t n, uint8_t p);

	/**
	 * @brief Matrix multiplication R = ABC.
	 * @param A m x n matrix.
	 * @param B n x p matrix.
	 * @param C p x q matrix.
	 * @return A pointer to the result (m x q).
	 */
	float* matmul(float *A, float *B, float *C, uint8_t m, uint8_t n, uint8_t p, uint8_t q);

	// ------------------------------| Linear algebra |------------------------------

	/// @return Compute the transposed matrix (n x m).
	float* transponse(float *A, uint8_t m, uint8_t n);

	/**
	 * @brief The algebric complement of the element (i,j).
	 * @param A 2 x 2 matrix.
	 */
	float algebric_complement2(const float *A, uint8_t i, uint8_t j);

	/**
	 * @brief The algebric complement of the element (i,j).
	 * @param A 3 x 3 matrix.
	 */
	float algebric_complement3(const float *A, uint8_t i, uint8_t j);

	/**
	 * @param A 2 x 2 Matrix.
	 * @return det(A).
	 */
	float det2(float *A);

	/**
	 * @param A 3 x 3 Matrix.
	 * @return det(A).
	 */
	float det3(float *A);

	/**
	 * @brief Compute the inverse matrix (3 x 3).
	 * @param A 3 x 3 matrix.
	 */
	float* inv3(float *A);

	// ------------------------------| Output |------------------------------

	/// @brief Get a string representation of your array or matrix.
	String toString(float *A, uint8_t m, uint8_t n, uint8_t width, uint8_t precision);

	/// @brief Print a string representation of your array or matrix.
	void print(float *A, uint8_t m, uint8_t n, uint8_t width, uint8_t precision);
}
