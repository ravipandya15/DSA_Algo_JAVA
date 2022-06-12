#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

string getSmallestString(int n, int k) {
    string res(n, 'a');
    k = k - n;

    while (k > 0)
    {
        res[n-1] += min(25, k);
        k -= min(25, k);
        n--;
    }
    return res;
}