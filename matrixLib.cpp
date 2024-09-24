#include "matrixLib.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

extern "C" {
    __declspec(dllexport) void fillMatrix(int matrix[10][6]) {
        srand(time(0));
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 6; ++j) {
                matrix[i][j] = rand() % 101 - 50;
            }
        }
    }

    __declspec(dllexport) void replaceMatrix(int matrix[10][6]) {
        std::vector<std::pair<int, int>> localMaxCoordinates; // Вектор для хранения координат локальных максимумов
        
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 6; ++j) {
                bool isLocalMax = true;
                
                // Проверяем левый сосед
                if (j > 0 && matrix[i][j] <= matrix[i][j - 1]) isLocalMax = false;
                // Проверяем правый сосед
                if (j < 5 && matrix[i][j] <= matrix[i][j + 1]) isLocalMax = false;

                if (isLocalMax) {
                    localMaxCoordinates.emplace_back(i, j); // Добавляем координаты локального максимума
                }
            }
        }

        // Вывод координат локальных максимумов
        std::cout << "Local maxima found at coordinates (row, column): ";
        for (const auto& coord : localMaxCoordinates) {
            std::cout << "(" << coord.first << ", " << coord.second << ") ";
        }
        std::cout << std::endl;
    }

    __declspec(dllexport) void printMatrix(const int matrix[10][6]) {
        std::cout << "Matrix:\n";
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 6; ++j) {
                std::cout << matrix[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }
}
