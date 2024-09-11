#include <iostream>

class Base {
public:
    Base(){std::cout<<"Base class constructor\n";}
    ~Base() {std::cout<<"Base class Desstructor";}  
   virtual void Show(){std::cout<<"Base class Show\n";}
};

class Derived : public Base {
public:
    Derived(){std::cout<<"Derived class constructor\n";}
    ~Derived() {std::cout<<"Derived class Desstructor";}
    void Show(){std::cout<<"Derived class Show\n";}
};

class OtherDerived : public Base {};

int main() {
    Base* base = new Derived();  // Points to a Derived object
    Derived* derived = dynamic_cast<Derived*>(base);  // Successful cast

    if (derived) {
         derived->Show(); // This will run because the cast is valid
    }

    // Now pointing to an object of a different derived class
    Base* base2 = new OtherDerived();
    Derived* derived2 = dynamic_cast<Derived*>(base2);  // Invalid cast
    std::cout<<"--------------------\n";
    if (derived2 == nullptr) {
        std::cout << "Cast failed, derived2 is nullptr" << std::endl;  // This will execute
    }
    std::cout<<"--------------------\n";
    Base*base3 = new OtherDerived();
    Derived*derived3 = static_cast<Derived*>(base3);
    if (derived3 == nullptr) {
        std::cout << "Cast failed, derived3 is nullptr" << std::endl;  // This will not execute
    }
    std::cout<<"----------Deleting----------\n";
    delete base;
    std::cout<<"\n";
    delete base2;
    std::cout<<"\n";
    delete base3;
    std::cout<<"\n";

    return 0;
}
