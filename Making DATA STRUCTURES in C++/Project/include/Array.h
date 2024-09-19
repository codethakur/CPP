#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <array>
#include <cstring>

template <typename T, size_t S>
class Array
{
public:
    constexpr int Size() const { return S; }

    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }

    #if 0
    T& operator[](size_t index)
    {
        if (!(index < S))
        {
            __debugbreak();
        }
        return m_Data[index];
    }
    #endif

    T* Data() { return m_Data; }
    const T* Data() const { return m_Data; }

private:
    T m_Data[S];
};

#endif 
