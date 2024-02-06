#include<iostream>

class Entity {
private:
	std::string m_Name;
  // int m_Count = 0;
	mutable int m_Count = 0;
public:
	const std::string& getName()const
	{
		m_Count++;
		std::cout << m_Count << std::endl;
		return m_Name;
	}
};

int main()
{
	Entity e;
	e.getName();
}
