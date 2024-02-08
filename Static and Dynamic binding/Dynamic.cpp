#include<iostream>
#include<list>

using namespace std;

class user
{
public:
	virtual void getInfo() {
		cout << "getInfo from VFunction" << endl;
	 }
};

class subuser:public user{
public:
	void getInfo() {
		cout << "getInfo from subuser Function" << endl;
	}
};

int main()
{
	user u;
	subuser su;

	list<user*> binding;

	binding.push_back(&u);
	binding.push_back(&su);

	for (user* ptr : binding) {
		ptr->getInfo();
	}

	system("pause>0");
}
