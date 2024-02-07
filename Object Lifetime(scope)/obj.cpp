#include<iostream>
#include<string>

class Entity {
public:
	Entity() {
		std:: cout<< "object is created:" << std::endl;

	}
	~Entity() {
		std::cout << "object is  no longer:" << std::endl;

	}

};
// partially can say-> unique_ptr

class ScoprPtr {
private:
	Entity* m_ptr;
public:
	ScoprPtr(Entity* ptr):m_ptr(ptr){}

	~ScoprPtr()
	{
		delete m_ptr;
	}
};

int  main()
{
	{
		ScoprPtr e = new Entity();// afert scope object is  no longer without using delete 

		/*Entity* e = new Entity;*/
	}

	
	{
		Entity* e = new Entity; // Allocate an Entity object
		delete e; // Deallocate the memory and call the destructor
	}
	
	std::cin.get();
}
