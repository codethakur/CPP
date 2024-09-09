#include<iostream>

namespace Apple{
    void printName(const char* text){
        std::cout<<text<<std::endl;
    }
    void model(const char* model){
        std::cout<<"model "<<model<<std::endl;
    }
}

namespace version{
    void Chipversion(const char* chip)
    {
        std::cout<<chip<<std::endl;
    }
}

namespace Company::Product::Module {
    class Widget {
    public:
        void doSomething() {
            std::cout<<"C++ 17 namespace attributes"<<std::endl;
        }
    };
}


int main()
{

    
    using Apple::printName;
    printName("iPhone");
    Apple::model("16");

    Company::Product::Module::Widget call;
    call.doSomething();

    #if 0
    using namespace Apple;
    printName("iPhone");
    model("16");
    using namespace version;
    Chipversion("A18");
    #endif

    std::cin.get();
}