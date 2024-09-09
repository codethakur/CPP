#include<iostream>
#include<vector>

void PrintValues(int value)
{
    std::cout<<" "<<value;
}

void ForEach(std::vector<int>values, void(*func)(int))
{
    for(auto value:values)
        func(value);
}
int main()
{
    std::vector<int>values = {1,4,2,3,8};

    ForEach(values, PrintValues);

    std::cin.get();
}
