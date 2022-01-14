#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Pow_of_x_to_n_50.cpp";
    return 0;
}

//Prefered way is Iterative

// C++ solution is not working 
double myPow(double x, int n) {
    //iterative
    double ans = 1.0;
    long nn = n;
    if (nn < 0)
        nn = -1 * nn;

    while(nn > 0)
    {
        if (nn % 2 == 1)
        {
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            x = x * x;
            nn = nn / 2;
        }
    }

    if (n < 0)
    {
        ans = (double)(1.0) / (double)ans;
    }
    return ans;
}

double myPow_Recursive(double x, int n) {
    //Recursion
    if (n < 0)
    {
        double ans = Recursion(x, double(-n));
        return (double)(1.0) / (double)(ans);

    }
    else
    {
        return Recursion(x, n);
    } 
}

double Recursion(double x, double n)
{
    if (n == 0) return 1;
    if (n == 1) return x;

    // Recursive call
    double ans = Recursion(x, n/2);
    if (((int)n & 1) == 0)
    {//even
        return ans * ans;
    }
    else
    {//odd
        return x * ans * ans;
    }
}
