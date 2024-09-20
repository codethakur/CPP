template <typename Vector>
class VectorIterator
{
public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

public:
    VectorIterator(PointerType ptr) : m_ptr(ptr) {}

    VectorIterator& operator++() // Prefix increment
    {
        ++m_ptr;
        return *this;
    }

    VectorIterator operator++(int) // Postfix increment
    {
        VectorIterator iterator = *this;
        ++m_ptr;
        return iterator;
    }

    VectorIterator& operator--() // Prefix decrement
    {
        --m_ptr;
        return *this;
    }

    VectorIterator operator--(int) // Postfix decrement
    {
        VectorIterator iterator = *this;
        --m_ptr;
        return iterator;
    }

    ReferenceType operator[](int index) const
    {
        return *(m_ptr + index);
    }

    ReferenceType operator*() const
    {
        return *m_ptr;
    }

    bool operator==(const VectorIterator& other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const VectorIterator& other) const
    {
        return m_ptr != other.m_ptr;
    }

private:
    PointerType m_ptr;
};

