#ifndef LOADLIB_H
#define LOADLIB_H

#include <iostream>

// Определяем условную компиляцию для разных ОС
#ifdef _WIN32
    #include <windows.h>
#else
    #include <dlfcn.h> // Для Linux используем dlfcn.h
#endif

class LoadLib {
public:
    LoadLib(const char* libName);
    ~LoadLib();

    template<typename FuncType>
    FuncType loadFunction(const char* funcName);

private:
    #ifdef _WIN32
        HINSTANCE hLib;  // Тип для Windows
    #else
        void* hLib;      // Тип для Linux
    #endif
};

template<typename FuncType>
FuncType LoadLib::loadFunction(const char* funcName) {
    if (!hLib) return nullptr;

    #ifdef _WIN32
        // Загрузка функции для Windows
        FuncType func = reinterpret_cast<FuncType>(GetProcAddress(hLib, funcName));
    #else
        // Загрузка функции для Linux
        FuncType func = reinterpret_cast<FuncType>(dlsym(hLib, funcName));
    #endif

    if (!func) {
        std::cerr << "Cannot load function: " << funcName << std::endl;
    }
    return func;
}

#endif // LOADLIB_H
