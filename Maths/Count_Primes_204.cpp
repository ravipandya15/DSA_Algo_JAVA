#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Count_Primes_204.cpp";
    return 0;
}

int countPrimes(int n) {
    int count = 0;
    // mark all number as prime
    //1->Prime , 0->Non Prime
    vector<bool> primes(n+1, true); 
    primes[0] = primes[1] = false;

    for (int i = 2; i < n; i++)
    {
        if (primes[i] == true)
        {
            count++;

            // mark number as non prime -> as i is there in table of j.
            for (int j = 2 * i; j < n; j = j + i)
            {
                primes[j] = false;
            }
        }
    }
    return count;
}