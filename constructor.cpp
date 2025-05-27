#include <iostream>
#include <cstring>

class String {
public:
    String(const char* str) {
        printf("created!\n");
        m_size = static_cast<uint32_t>(strlen(str)) ;
        m_data = new char[m_size + 1];
        memcpy(m_data, str, m_size + 1);
    }
    String(const String &other) {
        printf("Copied!\n");
        m_size = other.m_size;
        m_data = new char[m_size + 1];
        memcpy(m_data, other.m_data, m_size + 1);
    }
    #if 0
        // Shallow copy
           String(const String &other) {
               printf("Shallow Copied!\n");
               m_size = other.m_size;
               m_data = other.m_data;
           }
    #endif
    
    String(String &&other)noexcept
    {
        printf("movied!\n");
        m_size = other.m_size;
        m_data = other.m_data;
        
        other.m_size = 0;
        other.m_data = nullptr;
        
    }
    
    ~String() {
        printf("Destroyed!\n");
        delete[] m_data;
    }

    void PrintData() const {
        for(uint32_t i =0; i<m_size; i++){
            printf("%c", m_data[i]);
        }
        printf("\n");
    }

private:
    char* m_data;
    int32_t m_size;
};


class Entity
{
public:
    Entity(const String&Name): m_name(Name){}
    
    Entity(String&& name)
           : m_name(std::move(name)){}

    void PrintName()
    {
        m_name.PrintData();
    }
private:
    String m_name;
};

int main() {
    Entity entity("Thakur");
    entity.PrintName();
    
    
    return  0;
}



