#include <iostream>
#include <string>

class Printing {
public:
    virtual std::string GetName() = 0; // = 0 ->Pure Virtual Functions or called Interfaces in c# || abstract java
};

class Entity : public Printing {
public:
    std::string GetName() override { return "Entity"; }
};

class Player : public Entity {
private:
    std::string m_Name;
public:
    Player(const std::string& name)
        : m_Name(name) {}

    std::string GetName() override { return m_Name; }
};

int main()
{
    Entity* e = new Entity();
    std::cout << "Entity name: " << e->GetName() << std::endl;

    Player* p = new Player("Coder");
    std::cout << "Player name: " << p->GetName() << std::endl;

    delete e;
    delete p;

    std::cin.get();
}
