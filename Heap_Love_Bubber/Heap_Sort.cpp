#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// TC -> O(NLogN)
vector<int> heapSort(vector<int> &arr, int n)
{
    int size = n;
    while (size > 1)
    {
        // step 1: swap
        swap(arr[size], arr[1]);

        // step 2:
        size--;

        // step 3: call heapify function
        heapify(arr, n, 1);
    }
}

//  1 based indexing
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
