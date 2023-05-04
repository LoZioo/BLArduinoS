# BLArduinoS
Very simple BLAS (Basic Linear Algebra Subroutines) implementation for embedded devices inspired by the [numpy](https://github.com/numpy/numpy) library.

## Disclaimer
This is a minimal library absolutely not meant to be perfect:
1. It lacks many operations compared to a standard numerical computing library.
2. The operations are all potentially computationally expensive since this library was not designed to be optimized.
3. The methods used are numerically the simplest possible, but the library seems to be numerically stable if the sizes of the matrices used for calculations remain small.
4. Its use is recommended with matrices of extremely small maximum size, otherwise the program may crash due to memory exhaustion.
5. In order to avoid crashes due to memory exhaustion, manual deallocation of the arrays in use is required, or specifically through the destroy(float*) function, or completely through the destroyAll() function.

## Manually Test the library
- Install cmake, make and the g++ compiler.
- ./start.sh
- If you want to try some specific function, you can use the [main.cpp](src/main.cpp) file under src.

