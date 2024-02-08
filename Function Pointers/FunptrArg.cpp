#include<iostream>

void Helloword(int a)
{
	std::cout << "Namaste: " <<a<< std::endl;
}

int main()
{
	void(*FunctionName)(int);
	FunctionName = Helloword;

	FunctionName(22);
	FunctionName(25);
}
