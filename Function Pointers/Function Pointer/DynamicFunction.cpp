#include<iostream>

void Add(int a, int b)
{
    std::cout<<"Sum: "<< a + b<<std::endl;
}

void multily(int a, int b)
{
    std::cout<<"Product: "<< a* b<<std::endl;
}

void executeOpreation(void(*opration)(int, int), int x, int y)
{
    opration(x,y);
}

int main()
{
    void(*op)(int, int) = Add;
    executeOpreation(op, 5, 9);

    op=multily;
    executeOpreation(op, 5, 9);

    std::cin.get();
}

