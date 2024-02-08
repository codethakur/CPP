#include<iostream>

void Helloword()
{
	std::cout << "Namaste" << std::endl;
}

int main()
{
	auto function = Helloword;

	function();
	function();
}
