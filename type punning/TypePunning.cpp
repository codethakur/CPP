#include<iostream>
#include <typeinfo>  

struct vector2{

    float x, y;
};

struct vector4 
{
  union 
  {
    struct{
        float x, y, z, w;
    };
    struct{
        vector2 a, b;
    };
    
  };
    
};

void Printvector2(const vector2& vector)
{
    std::cout<<"a-> "<<vector.x<<" "<<"b-> "<<vector.y<<std::endl;
}

int main()
{
    #if 0
        //Type Punning
        int a  = 50;
        double value = a;
        std::cout<<"value: "<<value<<"\nmemory address: "<<&value<<std::endl;
        std::cout << "Data type of 'value': " << typeid(value).name() << std::endl;

    #endif
    vector4 vector = {1.0f, 2.0f, 3.0f, 4.0f};

    Printvector2(vector.a);
    Printvector2(vector.b);
    std::cout<<"----------------------"<<std::endl;
    // Access individual floats
    std::cout << "x -> " << vector.x << " y -> " << vector.y << std::endl;
    std::cout << "z -> " << vector.z << " w -> " << vector.w << std::endl;
    std::cout<<"----------------------"<<std::endl;
    vector.w = 400.0f;
    Printvector2(vector.a);
    Printvector2(vector.b);



    return 0;
}
