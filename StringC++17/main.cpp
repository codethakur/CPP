#include <iostream>
#include <string>
#include <memory>

// Global counter for allocations
std::size_t allocationCount = 0;

// Custom allocator that tracks memory allocations
template <typename T>
struct TrackingAllocator {
    using value_type = T;

    TrackingAllocator() = default;

    template <class U>
    constexpr TrackingAllocator(const TrackingAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        ++allocationCount; // Track allocations
        std::cout << "Allocating " << n * sizeof(T) << " bytes\n";
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t n) noexcept {
        ::operator delete(p);
    }
};

template <class T, class U>
bool operator==(const TrackingAllocator<T>&, const TrackingAllocator<U>&) { return true; }

template <class T, class U>
bool operator!=(const TrackingAllocator<T>&, const TrackingAllocator<U>&) { return false; }

int main() {
    // Use the custom allocator for std::string
    using TrackingString = std::basic_string<char, std::char_traits<char>, TrackingAllocator<char>>;

    TrackingString fullName = "Unknown Name"; // First allocation
    TrackingString fName = fullName.substr(0, 6); // Second allocation
    TrackingString sName = fullName.substr(7, 12); // Third allocation

    std::cout << "Total number of allocations:------ " << allocationCount << "\n";

    return 0;
}
