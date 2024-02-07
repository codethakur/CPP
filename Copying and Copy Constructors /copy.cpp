#include<iostream>
#include<string>

class String {
private:
	char* m_data;
	int m_size;
public:
	String(const char* string) {
		m_size = strlen(string);
		m_data = new char[m_size + 1];

		memcpy(m_data, string, m_size + 1);
	}
	~String() {
		delete m_data;
	}
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};
std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.m_data;
	return stream;
}

int main() 
{
	String str1 = "original";
	String str2 = str1;

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;


	std::cin.get();
}
