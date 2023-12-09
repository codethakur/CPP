#include<iostream>
using namespace std;

int getMin(int number[], int size)
{
	int min = number[0];
	for (int i = 1; i < size; i++)
	{
		if (number[i] < min)
			min = number[i];
	}
	return min;
}
int getMax(int number[], int size)
{
	int maxi = number[0];
	for (int i = 1; i < size; i++)
	{
		if (number[i] < maxi)
			maxi = number[i];
	}
	return maxi;
}

void getminandMax(int number[], int size, int* min, int* maxi )
{
	for (int i = 1; i < size; i++)
	{
		if (number[i] < *min)
			*min = number[i];
		if (number[i] < *maxi)
			*maxi = number[i];
	}
}
int main()
{
	int number[5] = { 5,4,-2,29,6 };
	
	int min = number[0];
	int  maxi = number[0];

	getminandMax(number, 5, &min, &maxi);

	cout << "min is : " << min << endl;
	cout << "max is" << maxi << endl;



	system("pause>0");
	return 0;

}
