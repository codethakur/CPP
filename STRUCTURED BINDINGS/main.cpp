#include <iostream>
#include <tuple>
#include <string>

std::tuple<std::string, int> Info()
{
    return {"C++ programming", 17};
}

int main()
{
    //std::tuple<std::string, int> Employe=EmployeeInfo();
    auto employe = Info();
    std::string& Name = std::get<0>(employe);
    int Age = std::get<1>(employe);
    std::cout << "Name: " << Name << " | Age: " << Age << std::endl;


    //std::tie(Name, Age) = EmployeeInfo();
    #if 0
        // C++ 17 structured binding
        auto [name, Age] = Info();
        std::cout << "Name: " << name << " | Age: " << Age << std::endl;
    #endif
    return 0;
}
