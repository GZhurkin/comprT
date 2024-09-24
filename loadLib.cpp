#include <iostream>
#include <stdexcept>

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#endif

class LoadLib {
public:
    LoadLib(const char* libName);
    ~LoadLib();

    void* getFunction(const char* funcName);

private:
    void* hLib = nullptr;
};

LoadLib::LoadLib(const char* libName) {
    #ifdef _WIN32
        // Загрузка библиотеки для Windows
        hLib = LoadLibraryA(libName);
        if (!hLib) {
            std::cerr << "Cannot load library: " << libName << " - Error Code: " << GetLastError() << std::endl;
            throw std::runtime_error("Failed to load library");
        }
    #else
        // Загрузка библиотеки для Linux
        hLib = dlopen(libName, RTLD_LAZY);
        if (!hLib) {
            std::cerr << "Cannot load library: " << libName << " - " << dlerror() << std::endl;
            throw std::runtime_error("Failed to load library");
        }
    #endif
}

LoadLib::~LoadLib() {
    if (hLib) {
        #ifdef _WIN32
            // Выгрузка библиотеки для Windows
            FreeLibrary(static_cast<HMODULE>(hLib));
        #else
            // Выгрузка библиотеки для Linux
            dlclose(hLib);
        #endif
    }
}

void* LoadLib::getFunction(const char* funcName) {
    if (!hLib) {
        throw std::runtime_error("Library is not loaded");
    }

    #ifdef _WIN32
        // Получение адреса функции для Windows
        FARPROC func = GetProcAddress(static_cast<HMODULE>(hLib), funcName);
        if (!func) {
            std::cerr << "Cannot load function: " << funcName << " - Error Code: " << GetLastError() << std::endl;
            return nullptr;
        }
        return reinterpret_cast<void*>(func);
    #else
        // Получение адреса функции для Linux
        void* func = dlsym(hLib, funcName);
        if (!func) {
            std::cerr << "Cannot load function: " << funcName << " - " << dlerror() << std::endl;
            return nullptr;
        }
        return func;
    #endif
}
