#include <iostream>
#include <memory>

struct object
{
    ~object()
    {
        std::cout << "Deleted\n";
    }
};

struct Manager
{
    std::weak_ptr<object> obj;  // Use weak_ptr to avoid dangling pointers

    void Fun()
    {
        // Check if the object still exists
        if (auto sharedObj = obj.lock())  // Convert weak_ptr to shared_ptr safely
        {
            // Access the object here, it is still valid
            std::cout << "Object is alive\n";
        }
        else
        {
            std::cout << "Object has been deleted\n";
        }
    }
};

Manager manager;

int main()
{
    // Create a shared_ptr to manage the object
    std::shared_ptr<object> obj = std::make_shared<object>();

    // Assign the weak_ptr to observe the object without owning it
    manager.obj = obj;

    // Reset the shared_ptr (object will be deleted since no more shared owners)
    obj = nullptr;

    // Call the function in Manager to check the object status
    manager.Fun();  // This will now safely check if the object still exists

    std::cin.get();
    return 0;
}
