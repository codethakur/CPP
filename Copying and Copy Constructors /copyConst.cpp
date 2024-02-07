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
		memcpy(m_data, string, m_size);
		m_data[m_size] = 0;
	}
	
	// Copy constructor
	String(const String& other) : m_size(other.m_size) {
		m_data = new char[m_size + 1];
		std::memcpy(m_data, other.m_data, m_size + 1);
	}
	~String() {
		delete[] m_data;
	}

	char& operator[](unsigned int index) {
		if (index < static_cast<unsigned int>(m_size)) {
			return m_data[index];
		}
		else {
			// Handle out-of-bounds access (you might want to throw an exception)
			// For simplicity, I'm returning the last character in the string
			return m_data[m_size - 1];
		}
	}


	// Copy assignment operator
	String& operator=(const String& other) {
		if (this != &other) {
			delete[] m_data;
			m_size = other.m_size;
			m_data = new char[m_size + 1];
			std::memcpy(m_data, other.m_data, m_size + 1);
		}
		return *this;
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
	
	str2[0] = 'n';

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;


	std::cin.get();
}
