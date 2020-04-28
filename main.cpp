#include <iostream> // for cout, cin, ...
#include <thread> // for threads
#include <unistd.h> // for sleep
#include <mutex> // mutex, unique_lock, ...
#include <vector>

struct Drum
{
    std::mutex mux;
};
Drum drum;

struct Drumstick
{
    std::mutex mux;
};
Drumstick stick;

// Play with the drum first
void playDrum(int childId)
{
    std::string id = std::to_string(childId);
    std::string line;
    std::unique_lock<std::mutex> drumLock(drum.mux, std::defer_lock);
    std::unique_lock<std::mutex> stickLock(stick.mux, std::defer_lock);

    //If you failed, try again
    while(!drumLock.owns_lock() || !stickLock.owns_lock())
    {
        if(!drumLock.owns_lock())
        {
            drumLock.lock();
            line = "Child " + id + ": I have the drum, time to get the drumstick!\n";
            std::cout << line;
        }
        sleep(1); // run to the other side of the room
        if(!stickLock.owns_lock())
        {
            stickLock.lock();
        }
    }
    line = "Child " + id + ": I have both! I can play! yay!\n\n";
    std::cout << line;
}

// Play with the stick first
void playDrumstick(int childId)
{
    std::string id = std::to_string(childId);
    std::string line;
    std::unique_lock<std::mutex> stickLock(stick.mux,std::defer_lock);
    std::unique_lock<std::mutex> drumLock(drum.mux, std::defer_lock);

    while(!drumLock.owns_lock() || !stickLock.owns_lock())
    {
        if(!drumLock.owns_lock())
        {
            drumLock.lock();
            line = "Child " + id + ": I have the stick, time to get the drum!\n";
            std::cout << line;
        }
        sleep(1); // run to the other side of the room
        if(!stickLock.owns_lock())
        {
            stickLock.lock();
        }
    }
    line = "Child " + id + ": I have both! I can play! yay!\n\n";
    std::cout << line;
}

// Spawn the children
std::vector<std::thread> toddlers; // globals are generally bad, however, this is to help in the event you decide to make a parent
void spawnToddlerThreads(int numToddlers)
{
    toddlers.resize(numToddlers);
    for(int i=0; i < numToddlers; ++i)
    {
        if(i%2 == 0)
        {
            toddlers[i] = std::thread(playDrum, i);
        }
        else
        {
            toddlers[i] = std::thread(playDrumstick, i);
        }
    }
    for(int i=0; i<numToddlers; ++i)
    {
        toddlers.at(i).join();
    }
}

int main(int argc, char *argv[])
{
    spawnToddlerThreads(5);
    // TODO:
    // Currently this causes a deadlock. Fix the deadlock with minimum changes to the existing code.
    // If you're feeling particularly adventurous create a parent to force the toddlers to share.
}
