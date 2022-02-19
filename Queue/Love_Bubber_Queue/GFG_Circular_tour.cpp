#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int main()
{
    return 0;
}

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    int start = 0;
    int deficit = 0;
    int balance = 0;

    for (int i = 0; i < n; i++)
    {
        balance = balance + p[i].petrol - p[i].distance;
        if (balance < 0)
        {
            deficit = deficit + balance;
            start = i + 1;
            balance = 0;
        }
    }

    if (deficit + balance >= 0)
    {
        return start;
    }
    return -1;
}