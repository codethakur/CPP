#include<iostream>

class Base
{
public:
    Base(){std::cout<<"Base class constructors\n";}
    # if 0
        ~Base(){std::cout<<"Base class destructors\n";}
    #endif

   virtual ~Base(){std::cout<<"Base class destructors\n";}
};
class Derive :public Base
{
public:    
    Derive(){std::cout<<"Derive class constructor\n";}
    
    ~Derive(){std::cout<<"Derive class destructors\n";}
};


int main()
{
    Base* base= new Base();
    delete base;
    std::cout<<"```````````````````\n";
    Derive* derive = new Derive();
    delete derive;
    std::cout<<"```````````````````\n";

    Base *Poly = new Derive();
    delete Poly;
    
    return 0;
}