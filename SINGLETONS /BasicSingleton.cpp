#include <iostream>
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mtx;  
    
    Singleton() {}  

public:
    static Singleton* GetInstance() {
        std::lock_guard<std::mutex> lock(mtx);  // Thread-safe, but adds overhead
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    // Prevent copying
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    void ShowMessage() {
        std::cout << "Singleton pattern in C++" << std::endl;
    }
};

// Initialization of static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;

int main()
{
    Singleton* S1 = Singleton::GetInstance();
    S1->ShowMessage();

    return 0;
}
