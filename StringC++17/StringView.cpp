#include <iostream>
#include <string>
#include <cstdint>

// Global counter for allocations
static uint32_t s_AllocCount = 0;

// Overload new operator to track allocations
void * operator new[](size_t size) {
    s_AllocCount++;
    std::cout << "Allocating " << size << " bytes\n";
    return malloc(size);
}

// Overload delete operator to track deallocations (optional, for completeness)
void operator delete(void* pointer) noexcept {
    free(pointer);
}

// Function to print a string
void PrintString(const std::string& name) {
    std::cout << name << std::endl;
}

int main() {
    const char *fullname = "Kishan Thakur";
    #if 0
        std::string fName = std::string(fullname).substr(0, 6);    
        std::string sName = std::string(fullname).substr(7, 12);
    #endif

    PrintString(fullname);

    // Use std::string_view to avoid additional allocations
    std::string_view fname(fullname, 6);
    std::string_view sname(fullname + 7, 6);

    std::cout << "First Name: " << fname << std::endl;
    std::cout << "Last Name: " << sname << std::endl;

    std::cout << s_AllocCount << " Allocations\n";

    return 0;
}
