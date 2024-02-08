#include<iostream>
#include<thread>
#include<chrono>


int main() 
{
	using namespace std::literals::chrono_literals;

	auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(1s);

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<float>time = end - start;

	std::cout<<"Total Time is:  " << time.count() << "s" << std::endl;


	std::cin.get();
}
