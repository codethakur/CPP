//Callback Mechanism
#include<iostream>

void onButtonClick()
{
    std::cout<<"Button Clicked!"<<std::endl;
}
void setClickHandler(void(*callBack)())
{
    callBack();
}

int main()
{
    setClickHandler(onButtonClick);

    std::cin.get();
}