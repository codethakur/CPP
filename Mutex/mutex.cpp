#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

mutex CarMutex;

void driveCar(string driverName)
{
    /*lock_guard<mutex> lock(CarMutex); if you this than no need for  this CarLock.unlock();*/

    unique_lock<mutex>CarLock(CarMutex);

    cout << driverName << " is driving" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << driverName << " finished driving" << endl;
    CarLock.unlock();
}

int main()
{
    thread t1(driveCar, "Rebert T");
    thread t2(driveCar, "Kiyosaki");

    t1.join();
    t2.join();

    cin.get();
}

