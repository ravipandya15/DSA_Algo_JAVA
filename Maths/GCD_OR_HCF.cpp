#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "GCD_OR_HCF.cpp";
    int a = 24, b = 72;
    cout << "GCD of" << a << " and " << b << " is " << GCD(a,b) << endl;
    return 0;
}

int GCD(int a, int b)
{
    if (a == 0) return b;
    if (b == 0) return a;

    while (a != b)
    {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}