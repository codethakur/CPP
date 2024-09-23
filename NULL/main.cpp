#include <iostream>
#include <cstddef> // For offsetof
#include <string>  // For std::string
#include <cstdint> // For uint64_t

struct Entity
{
public:
    std::string getName() const { return m_Name; }
    void PrintEntity() {
        std::cout << "Entity\n";
    }

    // Friend declaration to allow access to private members
    friend struct EntityAccess;

private:
    Entity *m_parent;
    std::string m_Name;
    int value;
};

// A separate struct to access private members for demonstration
struct EntityAccess {
    static void printOffsets() {
        size_t offset = offsetof(Entity, m_Name);
        std::cout << "offsetof m_Name: " << offset << " bytes" << std::endl;

        // Using pointer arithmetic to calculate the offset
        offset = reinterpret_cast<uint64_t>(&((Entity*)0)->m_Name);
        std::cout << "Calculated offset of m_Name: " << offset << " bytes" << std::endl;
    }
};

int main()
{
    EntityAccess::printOffsets(); // Call the function to print offsets

    #if 0
        Entity *e = nullptr;
        e->getName(); // This would cause a null pointer dereference if executed
    #endif

    return 0;
}
