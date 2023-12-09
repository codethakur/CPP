#include<iostream>
#include<memory>
using namespace std;

class MyClass
{
public:
	MyClass() {
		cout << "Constructor" << endl;
	}
	~MyClass() {
		cout << "Deconstructor" << endl;
	}
};

int main()
{
	{
		shared_ptr<MyClass>ShPtr1 = make_shared<MyClass>();
		cout << "Shared Count:" << ShPtr1.use_count() << endl;

		{
			shared_ptr<MyClass>ShPtr2 = ShPtr1;
			cout << "Shared Count of ShPtr2:" << ShPtr2.use_count() << endl;
		}
		cout << "Shared Count of ShPtr1:" << ShPtr1.use_count() << endl;
	}

	system("pause>0");

}