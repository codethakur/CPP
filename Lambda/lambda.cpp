#include <iostream>
#include <vector>
#include<algorithm>

void PrintValue(int value)
{
    std::cout << value;
}

void ForEach(const std::vector<int> values, void (*fun)(int))
{
    for (int value : values)
        fun(value);
}

int main()
{
    std::vector<int> values = {1, 2, 3, 6, 5, 4};

    // CallBack
    ForEach(values, [](int value){ std::cout << "Value: " << value << ", "; });

    std::cout<<"\n OR use of std::for_each "<<"\n";
    std::for_each(values.begin(), values.end(), [](int n){ std::cout << "Value: " << n << ", "; });
    
    std::cout << "\n";

    // Inline function
    auto square = [](int x)
    { return x * x; };
    std::cout << "\nSquare of 5: " << square(5) << std::endl;

    //Capturing Variables
    int factor=2;
    auto multiply = [factor](int X) {return X *factor; };
    std::cout << "\n5 multiplied by factor: " << multiply(5) << std::endl;

    std::sort(values.begin(), values.end(), [](int a, int b){return a>b;});
    for(auto value:values)
        std::cout<<value<<" ";
   
    // Immutability by Default:

    int a = 10;
    auto lambda = [a]() mutable{a++; return a; };
    std::cout <<"\nImmutability\n" << lambda() << std::endl;

    return 0;
}