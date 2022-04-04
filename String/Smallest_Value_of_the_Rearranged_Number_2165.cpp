#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

long long smallestNumber(long long num) {
    string str = to_string(abs(num));
    if (num > 0)
    {
        sort(str.begin(), str.end());
    }
    else
    {
        sort(str.begin(), str.end(), greater<char>());
    }

    if (num > 0)
    {
        int index = str.find_first_not_of('0');
        swap(str[0], str[index]);
    }

    long long ans = stoll(str);
    if (num < 0) 
    {
        ans = ans * -1;
    }

    return ans;
}