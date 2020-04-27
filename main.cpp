#include <iostream> // for cout, cin, ...
#include <thread> // for threads
#include <chrono> // for wibbly-wobbly time
#include <unistd.h> // for sleep

void helloWorld(std::string adj, int id)
{
    std::cout << "Hello " << adj << " World " << id << "!" << std::endl;
    sleep(2); // This helps to break up the printing and show what's actually happening where
}

int main(int argc, char *argv[])
{
    // TODO:
    // 1. Create a function called helloSerialWorlds(int numTimes)
    //    * Start a timer at the top of the function
    //    * call helloWorld() numTimes with different ids, passing in "Serial" as the adj argument
    //    * Stop the timer and return how long the function took
    // 2. Create a function called helloConcurrentWorld(int numTimes)
    //    * Start a timer at the top of the function
    //    * call helloWorld() numTimes, passing in "Concurrent" as the adj argument; this time spawn a thread for each call
    //    * join threads [HINT: Be aware of your scope and where you do this, joining prematurely will render the threads useless]
    //    * Stop timer and return how long the function took
    // 3. Call both functions in main with the same numTimes
    // 4. Print times for each function
}
