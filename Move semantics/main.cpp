#include <iostream>
#include <cstdint>
#include <cstring>


class String
{
public:
    String() = default;
    String(const char *string)
    {
        std::cout << "Created!\n";
        m_size = strlen(string);
        m_data = new char[m_size];
        memcpy(m_data, string, m_size);
    }

    String(const String& other)
    {
        std::cout << "Copid!\n";
        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
    }

    //Move semantics
    String(String&& other)
    {
        std::cout << "Movied!\n";
        m_size = other.m_size;
        m_data=other.m_data;

        other.m_size =0;
       other.m_data=nullptr;
    }

    void Print()
    {
        for(uint32_t i =0; i<m_size; i++)
            std::cout<<m_data[i];
        std::cout<<"\n";    
    }
    ~String()
    {
        std::cout << "destroyed!\n";
        delete m_data;
    }

private:
    char *m_data;
    uint32_t m_size;
};

class Entity
{
public:
    Entity(const String &name) : m_Name(name) {}

    Entity(const String &&name) : m_Name((String&&)name) 
    {

    }
    void PrintName()
    {
        m_Name.Print();
    }

private:
    String m_Name;
};

int main()
{
    Entity entity(String("Dell"));
    entity.PrintName();

    std::cin.get();
}