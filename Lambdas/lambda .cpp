#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

void ForEach(std::vector<int>& values, const std::function<void(int)>& func) //auto& func
{
    for (int value : values) {
        func(value);
    }
}

int main()
{
    std::vector<int> values = { 1, 5, 6, 9 };

    auto lambda = [](int value) {
        std::cout << "Values: " << value << std::endl;
    };

    ForEach(values, lambda);

    std::cin.get();
}
