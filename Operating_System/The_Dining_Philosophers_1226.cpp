// #include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    return 0;
}

class Semaphore
{
    public:
    int count;
    mutex mx;
    condition_variable cv;
    Semaphore() {}
    // Semaphore(int c) : count(c){};

    void setCount(int c)
    {
        this->count = c;
    }

    inline void wait()
    {
        unique_lock<mutex> lock(mx);
        count--;
        while (count < 0)
        {
            cv.wait(lock);
        }
    }

    inline void signal()
    {
        unique_lock<mutex> lock(mx);
        count++;
        if (count <= 0)
        {
            cv.notify_one();
        }
    }
};

class DiningPhilosophers {
public:
    Semaphore fork[5];
    mutex m;
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        {
            lock_guard<mutex>lock(m);
            fork[philosopher].wait();
            fork[(philosopher % 5)].wait();
        }

        pickLeftFork();
        pickRightFork();

        eat();

        putLeftFork();
        putRightFork();
        fork[philosopher].signal();
        fork[(philosopher % 5)].signal();
		
    }
};