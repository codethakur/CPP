#include<iostream>
using namespace std;

float sumNumber(float a, float b)
{
	return a + b;
}

float sumNumber(float a, float b, float c)
{
	return a + b + c;
}


int main()
{
	std::cout<<sumNumber(1, 2)<<" ";
	std::cout << sumNumber(1, 2, 3);


	system("pause>0");
}
