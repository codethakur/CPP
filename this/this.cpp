#include <iostream>
#include <string>

#define Print std::cout <<
#define nL << std::endl

void PrintMethod(const Entity&e );                     // void PrintMethod(Entity*e );

class Entity
{
public:
    float x;
    float y;

    Entity(float X, float Y)
    {
        Entity *e = this; //== this->x=X;
        this->x = X;
        this->y = Y;

        //non const menthod

        Entity &e = *this;

        PrintMethod(*this);                            //PrintMethod(this);
       // delete this; //deallocates the memory for the object, Accessing Members After delete this;The program might crash, or you might access garbage data.
    }
    int get() const
    {
        const Entity &e = *this;
    }
};
void PrintMethod(Entity *e){
    //Print...
}
