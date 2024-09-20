#include "Array.h"
#include <iostream>
#include <string>
#include "Vector.h"

int main()
{
    Vector<int> values;
    values.EmplaceBack(1);
    values.EmplaceBack(2);
    values.EmplaceBack(3);
    values.EmplaceBack(4);

    std::cout << "Without Iterator\n";
    for (size_t i = 0; i < values.Size(); ++i)
    {
        std::cout << values[i] << " ";
    }

    std::cout << "\nRange-based for loop!\n";
    for (int value : values)
    {
        std::cout << value << " ";
    }

    std::cout << "\nIterator\n";
    for (Vector<int>::Iterator it = values.begin(); it != values.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}
