#include<iostream>
#include"Log.h"

int main()
{
	/*int i = 0;
	bool condition = true;
	for ( ; condition; )
	{
		Log("Namaste!");
		i++;
		if (!(i < 5)) 
			condition = false;
	}*/

	for (int i = 0; i < 5; i++)
	{
		Log("Namaste");
	}
	int i = 0;
	while (i<5)
	{
		Log("C++");
		i++;// if not i++ then infinite 🔁
	}
	int j = 6;//j=0;
	do {
		Log("Programmer");// at least once,
		j++;
	} while (j < 5);


	std::cin.get();
}
