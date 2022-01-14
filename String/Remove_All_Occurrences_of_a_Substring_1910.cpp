#include<iostream>
using namespace std;

int main()
{
    cout << "125 Valid Palindrome -> AMAZON";
    return 0;
}

string removeOccurrences(string s, string part) {
    while (s.find(part) < s.length())
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}