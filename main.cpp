#include "LoadLib.h"
#include <iostream>

// Определение типов функций
typedef void (*FillArrayFunc)(int[], int);
typedef void (*ReplaceArrayFunc)(int[], int);
typedef void (*PrintArrayFunc)(const int[], int);

typedef void (*FillMatrixFunc)(int[10][6]);
typedef void (*ReplaceMatrixFunc)(int[10][6]);
typedef void (*PrintMatrixFunc)(const int[10][6]);

int main() {
    int choice;
    std::cout << "Choose what to work with:\n";
    std::cout << "1. Array\n";
    std::cout << "2. Matrix\n";
    std::cin >> choice;

    if (choice == 1) {
        
        LoadLib arrayLib("arrayLib.dll");

        FillArrayFunc fillArray = arrayLib.loadFunction<FillArrayFunc>("fillArray");
        ReplaceArrayFunc replaceArray = arrayLib.loadFunction<ReplaceArrayFunc>("replaceArray");
        PrintArrayFunc printArray = arrayLib.loadFunction<PrintArrayFunc>("printArray");

        if (!fillArray || !replaceArray || !printArray) {
            return 1;
        }

        int arr[45];
        fillArray(arr, 45);
        printArray(arr, 45);
        replaceArray(arr, 45);
    } 
    else if (choice == 2) {
        
        LoadLib matrixLib("matrixLib.dll");

        FillMatrixFunc fillMatrix = matrixLib.loadFunction<FillMatrixFunc>("fillMatrix");
        ReplaceMatrixFunc replaceMatrix = matrixLib.loadFunction<ReplaceMatrixFunc>("replaceMatrix");
        PrintMatrixFunc printMatrix = matrixLib.loadFunction<PrintMatrixFunc>("printMatrix");

        if (!fillMatrix || !replaceMatrix || !printMatrix) {
            return 1;
        }

        int matrix[10][6];
        fillMatrix(matrix);
        printMatrix(matrix);
        replaceMatrix(matrix);
    } 
    else {
        std::cerr << "Invalid choice!" << std::endl;
    }

    return 0;
}
