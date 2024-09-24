#ifndef ARRAYLIB_H
#define ARRAYLIB_H

extern "C" {
	__declspec(dllexport) void fillArray(int arr[], int size);
	__declspec(dllexport) void replaceArray(int arr[], int size);
	__declspec(dllexport) void printArray(const int arr[], int size);
} 

#endif