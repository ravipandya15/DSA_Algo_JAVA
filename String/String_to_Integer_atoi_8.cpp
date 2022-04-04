#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

int myAtoi(string s) {

    int n = s.size();
    if (n == 0) return 0;
    
    int i = 0;

    while (i < n && s[i] == ' ')
    {
        i++;
    }

    s = s.substr(i);

    if (s.size() == 0) return 0;

    int sign = +1;
    long ans = 0;

    if (s[0] == '-') sign = -1;

    int maxi = INT_MAX;
    int mini = INT_MIN;
    i = (s[0] == '-' || s[0] == '+') ? 1 : 0;
    

    while (i < s.size()) // as n now changes because we removed extra whitespaces
    {
        if (s[i] == ' ' || !isdigit(s[i])) break;
        ans = ans * 10 + (s[i] - '0');

        if (sign == -1 && -1 * ans < mini) return mini;
        if (sign == 1 && ans > maxi) return maxi;

        i++;
    }

    return (int)(sign * ans);
}