#include<iostream>

void Helloword()
{
	std::cout << "Namaste" << std::endl;
}

int main()
{
	void(*FunctionName)();
	FunctionName = Helloword;

	FunctionName();
	FunctionName();
}
