#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// 0 based indexing
// left < n
void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

// CN Code -> for min heap -> 0 based indexing
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();

    for (int i = n/2-1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    return arr;
}
