#include <iostream>
#include <string>

class Entity {
private:
    std::string m_Name;
    int m_Age;

public:
    // Constructor for initializing with a name
    Entity(const std::string& name) : m_Name(name), m_Age(-1) {}

    // Constructor for initializing with an age
    // Entity(int age) : m_Name("Unknown"), m_Age(age) {}
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {}
};

void print(const Entity& entity) {

}
int main() {
    
    print(22);

    print(Entity(22));//explicit
    //Entity age = 22;


    print(Entity("CodeThakur"));// implicit
    Entity name  = "CodeThakur"; //not allowed 

    std::cin.get();

    return 0;
}
