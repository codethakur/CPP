#include <iostream>

struct MyClass {
    int value;

    // C++11 style explicit conversion to int
    explicit operator int() const {
        return value;
    }

    // Helper function for condition
    constexpr bool shouldAllowImplicitConversion() const {
        return value > 10;
    }

    // C++20 style conditional explicit conversion to int*
    explicit (not shouldAllowImplicitConversion()) operator int*() const {
        return const_cast<int*>(&value);
    }
};

int main() {
    MyClass obj1{5};   // value <= 10
    MyClass obj2{20};  // value > 10

    // C++11 explicit conversion to int
    int n1 = static_cast<int>(obj1); // Works with explicit cast
    std::cout << "n1 (obj1 to int): " << n1 << std::endl;

    // Implicit conversion to int* for obj2 (value > 10)
    int* p2 = obj2; // Allowed because value > 10
    std::cout << "p2 (obj2 to int*): " << p2 << std::endl;

    // C++11 explicit conversion to int for obj2
    int n2 = static_cast<int>(obj2); // Works with explicit cast
    std::cout << "n2 (obj2 to int): " << n2 << std::endl;

    // obj1 needs explicit conversion to int*
    int* p1 = static_cast<int*>(obj1); // Works with explicit cast
    std::cout << "p1 (obj1 to int*): " << p1 << std::endl;

    return 0;
}
