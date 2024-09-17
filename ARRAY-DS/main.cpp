#include <iostream>
#include <array>
#include <cstring>  


template <typename T, size_t S>

class Array
{
public:
    constexpr int Size() const { return S;}
    T& operator[](size_t index){return m_Data[index];}
    const T& operator[](size_t index) const{return m_Data[index];}
    #if 0
            T& operator[](size_t index)
            {
                if(!(index<s))
            {
                __debugbreak();
            }
            return m_Data[index];
            }
    #endif    
    T* Data() {return m_Data;}
    const T* Data() const{return m_Data;}

private:
    T m_Data[S];
};

int main()
{
    int size = 5;
    Array<int, 5>data;
    
    memset(&data[0], 0, data.Size()*sizeof(int));
    data[1]=1;
    data[4]=3;
    for(size_t i=0; i<data.Size(); i++)
    {

        std::cout<<i<<": "<<data[i]<<std::endl;
    }
    return 0;
}
