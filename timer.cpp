#include <iostream>
#include <thread>
#include <chrono>

struct Timer {
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        /*std::cout << "Duration: " << duration.count() << " seconds" << std::endl;*/
        std::cout << "Duration: " <<ms<< " ms" << std::endl;
    }
};

void TotalSumNumber() {
    Timer timer;
    int sum = 0;
    for (int i = 1; i < 100; i++) {
        sum += i;
        std::cout <<"   " << i << std::endl;

    }

    std::cout << "-------------------" << std::endl;
    std::cout << "TotalSum of Number is:  " << sum << std::endl;
}

int main() {
    TotalSumNumber();




    std::cin.get();
}
