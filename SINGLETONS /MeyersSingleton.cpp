#include <iostream>
class Singleton {
public:
    // Static method to provide access to the Singleton instance
    static Singleton& GetInstance() {
        static Singleton instance;  // Guaranteed to be thread-safe
        return instance;
    }

    // Example method
    void ShowMessage() {
        std::cout << "Meyers' Singleton in C++" << std::endl;
    }

private:
    // Private constructor
    Singleton() {
        std::cout << "Singleton instance created." << std::endl;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

int main() {
    Singleton& s1 = Singleton::GetInstance();
    s1.ShowMessage();

    return 0;
}
