#include <iostream>
#include <cstring>

class String
{
private:
    char *m_Buffre;
    unsigned m_size;

public:
    String(const char *string)
    {
        m_size = strlen(string);
        m_Buffre = new char[m_size + 1]; 
        memcpy(m_Buffre, string, m_size);
        m_Buffre[m_size] = 0; 
    }

    // Copy Constructor
    String(const String&other):m_size(other.m_size)
    {
        m_Buffre = new char[m_size+1];
        memcpy(m_Buffre, other.m_Buffre, m_size+1);
    }
   
    
    ~String()
    {
        delete[] m_Buffre;
    }
    
    char& operator[](unsigned int index)
    {
        return m_Buffre[index];
    }
    
    friend std::ostream &operator<<(std::ostream &stream, const String &string);
};

std::ostream &operator<<(std::ostream &stream, const String &string)
{
    stream << string.m_Buffre;
    return stream;
}

int main()
{
    String string = "Kishan";
    String second = string;
    second[1] = 'y';

    std::cout << string << std::endl; 
    std::cout << second << std::endl; 

    return 0;
}
