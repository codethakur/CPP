#include<iostream>
#include<vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

int main()
{
    std::vector<Vertex>vertces;

    vertces.reserve(3);

    vertces.push_back({ 1, 2, 3 });
    vertces.push_back({ 8, 9, 3 });
    vertces.push_back({ 7, 6, 5 });

    for (auto i : vertces) {
        std::cout << i << std::endl;
    }

    std::cout << &vertces << std::endl;

    system("pause>0");
}
