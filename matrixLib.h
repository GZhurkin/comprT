#ifndef MATRIXLIB_H
#define MATRIXLIB_H

extern "C" {
	__declspec(dllexport) void fillMatrix(int matrix[10][6]);
	__declspec(dllexport) void replaceMatrix(int matrix[10][6]);
	__declspec(dllexport) void printMatrix(const int matrix[10][6]);
}

#endif