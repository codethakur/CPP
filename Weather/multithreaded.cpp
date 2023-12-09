#include<iostream>
#include<thread>
#include<map>
#include<string>
#include<chrono>

using namespace std::chrono_literals;

void refreshForecast(std::map<std::string, int>& ForecastMap) {  
    while (true) {
        for (auto& item : ForecastMap) { 
            item.second++;
            std::cout << item.first << "-" << item.second << std::endl;  
        }
        std::this_thread::sleep_for(2000ms);
    }
}

int main() {
    std::map<std::string, int> ForecastMap{
        {"Bengaluru", 27},
        {"Patna", 25}, 
        {"California", 7}
    };

    std::thread bgWork(refreshForecast, std::ref(ForecastMap));

    system("pause>0");
    return 0;
}
