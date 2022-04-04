#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// with 1 based indexing
// left <= n
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
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
