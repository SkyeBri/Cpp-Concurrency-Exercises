#include <iostream> // for cout, cin, ...
#include <thread> // for threads
#include <chrono> // for wibbly-wobbly time
#include <unistd.h> // for sleep
#include <vector>


void helloWorld(std::string adj, int id)
{
    std::cout << "Hello " << adj << " World " << id << "!" << std::endl;
    sleep(2);
}

double helloSerialWorlds(int numTimes)
{
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < numTimes; ++i)
    {
        helloWorld("Serial", i);
    }

    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(stop-start).count();
}

double helloConcurrentWorlds(int numTimes)
{
    auto start = std::chrono::high_resolution_clock::now();

    std::vector<std::thread> threads;
    threads.resize(numTimes);
    for(int i = 0; i < numTimes; ++i)
    {
        threads.at(i) = std::thread(helloWorld, "Concurrent", i);
    }

    for(auto &t : threads)
    {
        t.join();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(stop-start).count();
}

int main(int argc, char *argv[])
{
    int numTimes = 3;
    double serial = helloSerialWorlds(numTimes);
    double concur = helloConcurrentWorlds(numTimes);
    std::cout << std::endl << "Num Times: " << numTimes << std::endl;
    std::cout << "Serial Duration : " << serial <<std::endl;
    std::cout << "Concurrent Duration: " << concur << std::endl;
}
