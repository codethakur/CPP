#include <iostream>
#include <string>
#include <unordered_map>
#include<map>
#include <cstdint>

struct EmployeeInfo
{
    std::string Name;
    uint32_t EmpId;
    double experience;
};
namespace std {
    template<>
    struct hash<EmployeeInfo> {
        size_t operator()(const EmployeeInfo& key) const {
            return hash<std::string>()(key.Name);  
        }
    };
}

int main()
{


        std::map<std::string, EmployeeInfo> EmployeeMap;
        EmployeeMap["Alice Johnson"] = EmployeeInfo{"Alice Johnson", 1001, 5.2};
        EmployeeMap["Bob Smith"] = EmployeeInfo{"Bob Smith", 1002, 3.0};
        EmployeeMap["Charlie Brown"] = EmployeeInfo{"Charlie Brown", 1003, 7.5};
    
    std::cout << "-------------------------\n";


    const auto& empmap=EmployeeMap;

    if(empmap.find("Santosh")!= empmap.end())
    {
        const EmployeeInfo &Santosh = empmap.at("Santosh");

    }
    //const EmployeeInfo &Santosh = empmap.at("Santosh");
    // Santosh.Name = "Santosh";
    // Santosh.EmpId = 1245;
    // Santosh.experience = 2.5;



    //C++17
    for(auto[name,Id]:EmployeeMap)
    {
        std::cout<<"Name: "<<name<<", "<<"Emp ID: "<<Id.EmpId<<"\n";
    }

    


    #if 0
        
        //alternative way

        EmployeeInfo newEmp;
        newEmp.EmpId=456;
        newEmp.experience=6.5;
        newEmp.Name="Sharin";
        EmployeeMap["Sharin"]= newEmp;
        for (const auto &entry : EmployeeMap)
        {
            const std::string &key = entry.first;
            const EmployeeInfo &employee = entry.second;

            std::cout << "Memory allocated for " << key << " at: " << &employee << std::endl;
            std::cout << "Ename: " << employee.Name << std::endl;                        // Default value (empty)
            std::cout << "EmpId: " << employee.EmpId << std::endl;                       // Default value (0)
            std::cout << "Experience: " << employee.experience << " years" << std::endl; // Default value (0.0)
            std::cout << "-------------------------\n";
        }
    #endif
    return 0;
}
