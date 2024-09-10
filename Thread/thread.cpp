#include <iostream>
#include <thread>

void printMessage() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t1(printMessage);  
    t1.join(); 
    return 0;

    
}
