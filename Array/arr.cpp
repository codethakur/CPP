#include<iostream>

int main() {
    int example[5];
    int* ptr = example;

    // Initialize elements of example array with the value 2
    for (int i = 0; i < 5; i++) {
        example[i] = 2;
    }

    // Dynamically allocate another array (anotherArr) and initialize its elements with the value 3
    int* anotherArr = new int[5];
    for (int i = 0; i < 5; i++) {
        anotherArr[i] = 3;
    }

    // Calculate the number of elements in the example array
    int count = sizeof(example) / sizeof(int);

    // Print the count of elements in the example array
    std::cout << count << std::endl;

    // Print the value at the first element of the example array
    std::cout << *example << std::endl;
  
    std::cout << example << std::endl; //address

    // Deallocate the dynamically allocated memory for anotherArr
    delete[] anotherArr;

    std::cin.get();
}
