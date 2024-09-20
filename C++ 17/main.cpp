#include <iostream>
#include <optional>
#include <variant>
#include <tuple>
#include <vector>

// Function that returns a tuple (demonstrating structured bindings)
std::tuple<int, std::string> getPerson() {
    return { 25, "John Doe" };
}

// Function that returns an optional value
std::optional<int> findElement(const std::vector<int>& vec, int target) {
    for (int elem : vec) {
        if (elem == target) {
            return elem;
        }
    }
    return std::nullopt; // C++17 std::optional usage
}

// Function that demonstrates std::variant and if constexpr
void printVariant(const std::variant<int, float, std::string>& v) {
    if constexpr (std::is_same_v<decltype(v), const std::variant<int, float, std::string>&>) {
        std::visit([](auto&& arg) {
            std::cout << "Variant holds: " << arg << '\n';
        }, v);
    }
}

int main() {
    // Using structured bindings (C++17)
    auto [age, name] = getPerson();
    std::cout << "Name: " << name << ", Age: " << age << "\n";

    // Using std::optional (C++17)
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    auto result = findElement(numbers, 3);
    
    if (result) {
        std::cout << "Element found: " << *result << '\n';
    } else {
        std::cout << "Element not found\n";
    }

    // Using std::variant (C++17)
    std::variant<int, float, std::string> v = 42;
    printVariant(v);

    v = 3.14f;
    printVariant(v);

    v = "C++17 is awesome!";
    printVariant(v);

    return 0;
}
