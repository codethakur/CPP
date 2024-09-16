#include <iostream>
#include <memory>
#include <string>

struct AllocationMetrics
{
    uint32_t TotalAllocated = 0;
    uint32_t FreeAllocated = 0;
    uint32_t CurrentUse() { return TotalAllocated - FreeAllocated; }
};

static AllocationMetrics s_AllocationMetrics;

void* operator new(size_t size)
{
    s_AllocationMetrics.TotalAllocated += size;
    std::cout << "Allocated: " << size << " bytes!" << std::endl;
    return malloc(size);
}

void operator delete(void* memory, size_t size)
{
    s_AllocationMetrics.FreeAllocated += size;
    std::cout << "free-> " << size << " bytes" << std::endl;
    free(memory);
}

static void PrintMemoryAllocated()
{
    std::cout << "Memory Allocated: " << s_AllocationMetrics.CurrentUse() << " bytes\n";
}

struct object
{
    float x, y, z;
};

int main()
{
    PrintMemoryAllocated();
    std::cout << "-----------------\n";

    std::string str = "This is a very long string, definitely longer than the small string optimization limit!";

    PrintMemoryAllocated();
    std::cout << "-----------------\n";

    {
        std::unique_ptr<object> obj = std::make_unique<object>();
        PrintMemoryAllocated();
    }

    PrintMemoryAllocated();

    return 0;
}
