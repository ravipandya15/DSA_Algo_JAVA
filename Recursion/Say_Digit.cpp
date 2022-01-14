#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "CN_Count_Ways_To_Reach_The_N_th_Stairs.cpp";
    return 0;
}


// Normal question from Cpdehelp -> Love bubber -> Lecture 32 -> Recursion
// string[] contains {"One", "Two", "Three", .........., "Nine"}
void sayDigit(int n, string arr[])
{
    if (n == 0) return;
    int digit = n % 10;
    n /= 10;
    sayDigit(n, arr);
    cout << arr[digit] << " ";
}