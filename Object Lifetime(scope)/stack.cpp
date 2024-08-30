#include <iostream>
#include <string>

#define Print std::cout <<
#define nL << std::endl                   
class Entity
{
public:
    Entity(){
        Print "Entity is Created!" nL;
    }
    ~Entity(){
        Print "Entity is Destroyed!" nL;
    }


};

class ScopePtr{
private:
    Entity *m_ptr;
public:
    ScopePtr(Entity *ptr):m_ptr(ptr){}

    ~ScopePtr(){ delete m_ptr; }
};


int main()
{
    ScopePtr e = new Entity();


    return 0;
}

