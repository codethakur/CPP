template <typename T>
class Vector
{
public:
    Vector()
    {
        ReAlloc(2);
    }

    ~Vector()
    {
        Clear();
        ::operator delete(m_data, m_Capacity*sizeof(T));
    }

    void PushBack(T &&value) // Overload for rvalue references (move semantics)
    {
        if (m_size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        m_data[m_size] = std::move(value); // Move the object
        m_size++;
    }

    void PushBack(const T &value) // Overload for lvalue references (copy semantics)
    {
        if (m_size >= m_Capacity)
            ReAlloc(m_Capacity + m_Capacity / 2);

        m_data[m_size] = value; // Copy the object
        m_size++;
    }

    // EmplaceBack to construct an element in-place
    template <typename... Args>
    void EmplaceBack(Args &&...args)
    {
        if (m_size >= m_Capacity)
            ReAlloc(m_Capacity * 2);

        // Construct the element in-place using the forwarded arguments
        new (&m_data[m_size]) T(std::forward<Args>(args)...);
        m_size++;
    }

    void PopBack()
    {
        if(m_size>0)
        {
            m_size--;
            m_data[m_size].~T();
        }
    }

    void Clear()
    {
        for(size_t i=0; i<m_size; i++)
            m_data[i].~T();
        m_size=0;    
    }

    const T &operator[](size_t index) const
    {
        if (index >= m_size)
        {
            /* assert or handle error */
        }
        return m_data[index];
    }

    T &operator[](size_t index)
    {
        if (index >= m_size)
        {
            /* assert or handle error */
        }
        return m_data[index];
    }

    size_t Size() const { return m_size; }
private:
    void ReAlloc(size_t newCapacity)
    {
        T *newBlock = (T*)::operator new (newCapacity * sizeof(T));

        // if (newCapacity < m_size)
        //     m_size = newCapacity;

        for (size_t i = 0; i < m_size; i++)
            newBlock[i] = std::move(m_data[i]);

        for (size_t i = 0; i < m_size; i++)
           m_data[i].~T();
        ::operator delete(m_data, m_Capacity*sizeof(T));
           
        m_data = newBlock;
        m_Capacity = newCapacity;
    }

private:
    T *m_data = nullptr;
    size_t m_size = 0;
    size_t m_Capacity = 0;
};
