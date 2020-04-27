#include <iostream> // for cout, cin, ...
#include <thread> // for threads
#include <chrono> // for wibbly-wobbly time

void helloWorld(std::string adj, int id)
{
    std::cout << "Hello " << adj << " World " << id << "!" << std::endl;
}

int main(int argc, char *argv[])
{
    // TODO:
    // 1. Create a function called helloSerialWorld(int numTimes)
    //    * Start a timer at the top of the function
    //    * call helloWorld() numTimes with different ids, passing in "Serial" as the adj argument
    //    * Stop the timer and print how long the function took
    //
    // 2. Create a function called helloConcurrentWorld(int numTimes)
    //    * Start a timer at the top of the function
    //    * call helloWorld() numTimes, passing in "Concurrent" as the adj argument; this time spawn a thread for each call
    //    * join threads
    //    * Stop timer and print how long the function took
    //
    // 3. Call both functions in main with the same numTimes to see if/where multithreading makes a difference for this task
}
