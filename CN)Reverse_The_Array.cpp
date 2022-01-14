#include<iostream>
#include<vector>
using namespace std;

void reverseArray(vector<int> &arr , int m)
{
	int s = m + 1, e = arr.size() - 1;

    while (s <= e)
    {
        // swap arr[s] with arr[e]
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    int m = 2;

    reverseArray(arr, m);
    cout << "Printing reverse array" << endl;
    print(arr);
    return 0;
}