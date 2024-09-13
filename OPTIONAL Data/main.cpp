#include <iostream>
#include <string>
#include <fstream>
#include <optional>

std::optional<std::string> ReadFileString(const std::string& filePath) {
    std::ifstream stream(filePath);

    if (stream) {
        std::string result((std::istreambuf_iterator<char>(stream)),
                            std::istreambuf_iterator<char>());  // Read entire file content
        stream.close();
        return result;
    }
    return {};
}
int main() {
    std::optional<std::string> data = ReadFileString("code.txt");

    if (data.has_value()) {
        std::cout << "File read successfully!" << std::endl;
        std::cout << "File content: " << *data << std::endl;  // Dereference optional to get the string
    } else {
        std::cout << "File not found!" << std::endl;
    }

    return 0;
}
