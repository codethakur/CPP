#include<iostream>
#include<vector>

/*
void printValues(int values)
{
	std::cout << "Values: " << values << std::endl;

}
*/

void ForEach(std::vector<int>&values, void(*fun)(int))
{
	for (int value : values) {
		fun(value);
	}
}

int main()
{
	std::vector<int> values = { 1,5,6,9 };

	/*ForEach(values, printValues);*/
	ForEach(values, [](int value) {
		std::cout << "Values: " << value << std::endl;
		});


	std::cin.get();
}
