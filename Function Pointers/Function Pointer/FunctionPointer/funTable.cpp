//Implementing Function Tables
#include<iostream>

void stateOne() { std::cout << "State One" << std::endl; }
void stateTwo() { std::cout << "State Two" << std::endl; }
void stateThree() { std::cout << "State Three" << std::endl; }

int main() {
    void (*stateTable[3])() = { stateOne, stateTwo, stateThree };
    
    for(auto currentState: stateTable)
        currentState();  
         
    return 0;
}
