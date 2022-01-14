#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "CN) Modular Exponentiation";
    return 0;
}

int modularExponentiation(int x, int n, int m) {
	int result = 1;

    while (n > 0)
    {
        if (n & 1)
        {// odd
            result = (1LL * (result) % m * (x) % m) % m;
        }
        x = (1LL * (x) % m * (x) % m) % m;
        n = n >> 1; // divide by 2
    }
    return result;
}

