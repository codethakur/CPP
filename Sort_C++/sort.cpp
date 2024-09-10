#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

int main()
{
    std::vector<int>array = {3,5,1,4,2};

    std::sort(array.begin(), array.end());

    for(auto value:array)
        std::cout<<value<<" ";

    std::vector<int>array2 = {3,5,1,4,2};   
    std::sort(array2.begin(), array2.end(), std::greater<int>());
    std::cout<<"\n array2: ";
        for(auto value:array2)
            std::cout<<value<<" ";

    std::vector<int>array3 = {3,5,1,4,2};    
    std::sort(array3.begin(), array3.end(), [](int a, int b){return a<b;});
    std::cout<<"\n based on Lambda array3: ";
        for(auto value:array3)
            std::cout<<value<<" ";

    std::vector<int>array4 = {3,5,1,4,2};    
    std::sort(array4.begin(), array4.end(), [](int a, int b){
        if(a==1)
            return false;
        if(b==1)
            return true;    
    });
    std::cout<<"\n based on Compare comp array3: ";
        for(auto value:array4)
            std::cout<<value<<"  ";        

    return 0;    
}