#include <iostream>
#include <memory>

class Entity {
public:
    Entity() {
        std::cout << "object is created:" << std::endl;
    }

    ~Entity() {
        std::cout << "object is no longer:" << std::endl;
    }
};

int main() {
    std::shared_ptr<Entity> e = std::make_shared<Entity>();

    {
        std::cout << "shared_ptr use count: " << e.use_count() << std::endl;
    }

    {
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();

        std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();

        // Assigning a shared_ptr to another shared_ptr
        e = sharedEntity;
        std::cout << "shared_ptr use count: " << e.use_count() << std::endl;
        std::weak_ptr<Entity> weakPtr = sharedEntity;// not affect the reference count.
        std::cout << "shared_ptr use count: " << e.use_count() << std::endl;

    }

    // The Entity object is still alive because the shared_ptr e is still in scope

    return 0;
}
