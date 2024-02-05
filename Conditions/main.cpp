#include<iostream>
#include"Log.h"

int main()
{
	const char* ptr = nullptr;
	if (ptr)
		Log(ptr);
	else if (ptr == "Namaste")
		Log("Namaste");
	else
		Log("ptr is null");

	std::cin.get();
}
