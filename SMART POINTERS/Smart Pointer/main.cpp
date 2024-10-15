#include <iostream>
#include <memory>

int main() {
    // Using unique_ptr: Only owns ownership, cannot be shared
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(42);
    std::cout << "uniquePtr points to: " << *uniquePtr << std::endl;

    // Transfer ownership from uniquePtr to another unique_ptr
    std::unique_ptr<int> uniquePtr2 = std::move(uniquePtr);
    if (uniquePtr) {
        std::cout << "uniquePtr still owns the resource." << std::endl;
    } else {
        std::cout << "uniquePtr has transferred ownership to uniquePtr2." << std::endl;
    }
    std::cout << "uniquePtr2 points to: " << *uniquePtr2 << std::endl;

    // Using shared_ptr: Owns and increases ownership count
    std::shared_ptr<int> sharedPtr1 = std::make_shared<int>(100);
    std::cout << "sharedPtr1 points to: " << *sharedPtr1 << std::endl;
    std::cout << "sharedPtr1 use count: " << sharedPtr1.use_count() << std::endl;

    // Share ownership with another shared_ptr
    std::shared_ptr<int> sharedPtr2 = sharedPtr1;
    std::cout << "sharedPtr2 also points to: " << *sharedPtr2 << std::endl;
    std::cout << "sharedPtr1 use count after sharing: " << sharedPtr1.use_count() << std::endl;
    
    // Using weak_ptr: Observes shared_ptr without owning
    std::weak_ptr<int> weakPtr = sharedPtr1;
    std::cout << "sharedPtr1 use count after weakPtr: " << sharedPtr1.use_count() << std::endl;
    
    // Lock weak_ptr to access the resource
    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "lockedPtr (from weakPtr) points to: " << *lockedPtr << std::endl;
        std::cout << "sharedPtr1 use count while locked: " << sharedPtr1.use_count() << std::endl;
    } else {
        std::cout << "Resource is no longer available." << std::endl;
    }

    // Reset sharedPtr1 and observe the behavior of weak_ptr
    sharedPtr1.reset();
    std::cout << "sharedPtr1 is reset." << std::endl;
    if (auto lockedPtr = weakPtr.lock()) {
        std::cout << "lockedPtr (from weakPtr) still points to: " << *lockedPtr << std::endl;
    } else {
        std::cout << "Resource is no longer available after sharedPtr1 reset." << std::endl;
    }

    return 0;
}
