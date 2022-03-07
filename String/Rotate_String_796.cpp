#include<iostream>
using namespace std;

int main()
{
    return 0;
}

bool rotateString(string s, string goal) {
    return ((s.length() == goal.length()) && (s + s).find(goal) != -1);
}

