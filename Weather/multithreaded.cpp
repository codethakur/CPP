#include<iostream>
#include<thread>
#include<map>
#include<string>
#include<chrono>
#ifdef _WIN32
#include <Windows.h>
#else
#include <cstdlib>
#endif

using namespace std::chrono_literals;

void forcast(std::map<std::string, int>weather) {
	while (true) {
//#ifdef _WIN32
//		system("cls");
//#else
//		system("clear");
//#endif
		for (auto& item : weather) {
			item.second++;
			std::cout << item.first << " -> " << item.second << std::endl;
		}
		std::this_thread::sleep_for(2000ms);
	}

}

int main()
{
	std::map<std::string, int>weather = {
		{"BLR", 19},
		{"HYD", 23},
		{"CHAI", 18}
	};

	std::thread bgworking(forcast, weather);

	system("pause>0");

}
