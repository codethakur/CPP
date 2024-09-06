#include<iostream>
#include<array>

template<size_t N>
void PrintData(const std::array<int, N>& data)
{
    for(int i = 0; i < data.size(); ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::array<int, 5> data = {0, 1, 2, 3, 4};

    PrintData(data);

/*
 std::array<int, 5>data;
    data[0]=0;
    data[1]=1;
    data[2]=2;
    data[3]=3;
    data[4]=4;

    int Odata[5];
    Odata[0]=0;
    Odata[1]=1;
    Odata[2]=2;
    Odata[3]=3;
    Odata[4]=4;
*/

    std::cin.get();
    return 0;
}
