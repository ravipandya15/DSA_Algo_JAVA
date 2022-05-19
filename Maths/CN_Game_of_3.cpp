#include<iostream>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// asked in Amazon
long long int numOfPairs(vector<int> &arr) {
	vector<long long int> rem(3, 0);

    for (int i = 0; i < arr.size(); i++)
    {
        rem[arr[i] % 3]++;
    }

    long long int count = 0; // if we kept it as int only then will not get 100% test cases passed.

    // for 2 size of groups
    count += (rem[0] * (rem[0] - 1)) / 2;
    count += rem[1] * rem[2];

    // for 3 size of group
    count += (rem[0] * (rem[0] - 1) * (rem[0] - 2)) / 6;
    count += (rem[1] * (rem[1] - 1) * (rem[1] - 2)) / 6;
    count += (rem[2] * (rem[2] - 1) * (rem[2] - 2)) / 6; 
    count += rem[0] * rem[1] * rem[2];
    return count;
}