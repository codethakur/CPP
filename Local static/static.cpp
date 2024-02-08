#include<iostream>

void exampleFunction() {
    // Local static variable
    static int counter = 0;

    // Increment and display the value of the static variable
    std::cout << "Counter: " << ++counter << std::endl;
}

int main() {
    // Call the function multiple times
    exampleFunction();
    exampleFunction();
    exampleFunction();

    return 0;
}
