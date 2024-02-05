#include<iostream>
#define	LOG(x) std:: cout<<x<<std::endl;

int main()
{
    int value = 42;

    int* pointer = &value;
    int** doublePointer = &pointer;

	std::cin.get();
}
