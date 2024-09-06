#include <iostream>
#include <string>

template<typename T, int N>
class Array {
private:
    T m_array[N];  // Array of size N

public:
    // Method to get the size of the array
    int getSize() const { return N; }

    // Overload the subscript operator for accessing elements
    T& operator[](int index) { return m_array[index]; }

    // Const version of the subscript operator
    const T& operator[](int index) const { return m_array[index]; }
};

template<typename T, int N>
std::ostream& operator<<(std::ostream& stream, const Array<T, N>& array) {
    stream << "[";
    for (int i = 0; i < N; ++i) {
        stream << array[i];
        if (i < N - 1) {
            stream << ", ";
        }
    }
    stream << "]";
    return stream;
}

int main() {
    Array<std::string, 5> array;
    array[0] = "Hello";
    array[1] = "World";
    array[2] = "This";
    array[3] = "Is";
    array[4] = "Array";

    std::cout << array << std::endl;

    return 0;
}
