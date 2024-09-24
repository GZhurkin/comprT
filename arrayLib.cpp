#include "arrayLib.h" 
#include <iostream> 
#include <cstdlib> 
#include <ctime> 
#include <vector> 

extern "C" { 
    __declspec(dllexport) void fillArray(int arr[], int size) { 
        srand(time(0)); 
        for (int i = 0; i < size; ++i) { 
            arr[i] = rand() % 101 - 50; 
        } 
    } 

    __declspec(dllexport) void replaceArray(int arr[], int size) { 
        std::vector<int> localMaxIndices; // Вектор для хранения индексов локальных максимумов
        
        for (int i = 1; i < size - 1; i++) { 
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) { 
                localMaxIndices.push_back(i); // Добавляем индекс локального максимума
            } 
        }

        // Вывод индексов локальных максимумов
        std::cout << "Local maxima found at indices: ";
        for (size_t i = 0; i < localMaxIndices.size(); i++) {
            std::cout << localMaxIndices[i] << " ";
        }
        std::cout << std::endl; 
    } 

    __declspec(dllexport) void printArray(const int arr[], int size) { 
        std::cout << "Array: "; 
        for (int i = 0; i < size; ++i) { 
            std::cout << arr[i] << " "; 
        } 
        std::cout << std::endl; 
    } 
}
