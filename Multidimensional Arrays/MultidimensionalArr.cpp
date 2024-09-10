#include <iostream>
#include <string>
#include <chrono>


struct Timer
{
    // Declare start and end time points
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    Timer() {
        start = std::chrono::high_resolution_clock::now();  // Record the start time
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();  // Record the end time
        // Calculate the duration between start and end
        std::chrono::duration<float> duration = end - start;

        // Print the total time taken
        std::cout << "\nTotal time: " << duration.count() << " seconds\n" ;
    }
};

int main() {
    Timer timer;
    // Allocate memory for a 2D array of pointers to strings
    std::string** a2d = new std::string*[50];

    // Allocate memory for each row
    for (int row = 0; row < 50; ++row) {
        a2d[row] = new std::string[50];
    }

    // Initialize elements using row and column index
    for (int row = 0; row < 50; ++row) {
        for (int col = 0; col < 50; ++col) {
            a2d[row][col] = "Cell " + std::to_string(row) + "," + std::to_string(col);
        }
    }

    // Print all elements using nested loops
    for (int row = 0; row < 50; ++row) {
        for (int col = 0; col < 50; ++col) {
            std::cout << a2d[row][col] << " ";  // Access element
        }
        std::cout << std::endl;
    }

    // Deallocate memory: first deallocate each row, then the outer array
    for (int row = 0; row < 50; ++row) {
        delete[] a2d[row];  // Delete each row
    }
    delete[] a2d;  // Delete the outer array (array of pointers)

    return 0;
}
