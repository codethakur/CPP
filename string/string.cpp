  #include<iostream>
#include<string> 
                                      // string -> std C++  Class          STL

void PrintString(const std::string& string)
{
	std::cout << "String address in PrintString: " << &string << std::endl;
	std::cout << string << std::endl;
}


int main()
{
	std::string name = "Kishan";
	std::cout << name << std::endl;

	std::cout<<"name address: " << &name << std::endl;
	const bool containsI = name.find('i') != std::string::npos;

	PrintString(name);

	std::cout<<"PrintString address: " << PrintString << std::endl;

	
	
	
	
	
	
	
	system("pause>0");
}
