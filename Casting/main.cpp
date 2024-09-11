#include <iostream>

struct Base
{
    float X = 10.0f, Y;

    Base() { std::cout << "Base class Constructor\n"; }
    virtual ~Base() { std::cout << "Base class Destructor\n"; }

    virtual void Show()
    {
        std::cout << "Base Class Show:" << std::endl;
    }
};

struct Derived : public Base
{
    float z, w;

    Derived() { std::cout << "Derived class Constructor\n"; }
    ~Derived() { std::cout << "Derived class Destructor\n"; }

    void Show()
    {
        std::cout << "Drive Class Show:" << std::endl;
    }

    void HelloFromDrive()
    {
        std::cout << "HelloFromDrive\n";
    }
};

int main()
{
    Base *basePtr = new Derived();
    std::cout << "------------------------\n";

    basePtr->Base::Show();
    std::cout << "------------------------\n";

    Derived *drivePtr = static_cast<Derived *>(basePtr);
    basePtr->Show();
    drivePtr->Show();

    std::cout << "------------------------\n";

    drivePtr->HelloFromDrive();
    drivePtr->z = 10.05f;
    std::cout << drivePtr->z << "\n";

    return 0;
}
