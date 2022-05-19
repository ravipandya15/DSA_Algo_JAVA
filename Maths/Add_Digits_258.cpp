#include<iostream>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// Approach - 1
// TC -> Logarithmic
int addDigits(int num) 
{
    int sum = 0;
    while (num > 9)
    {
        while (num > 0)
        {
            sum += num % 10;
            num = num / 10;
        }
        num = sum;
        sum = 0;
    }
    return num;
}

// Approach - 2
// TC -> O(1)
int addDigits(int num) 
{
    if (num == 0) return 0;
    return num % 9 == 0 ? 9 : num % 9;
}

