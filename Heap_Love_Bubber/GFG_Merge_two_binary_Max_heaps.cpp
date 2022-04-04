#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

// 0 based indexing
void heapify(vector<int> &arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left <= size && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int> ans;
    // step 1: merge 2 vectors
    for (auto i : a)
    {
        ans.push_back(i);
    }
    for (auto i : b)
    {
        ans.push_back(i);
    }

    int size = ans.size();

    // step 2: call heapify function
    for (int i = size/2 -1 ; i>= 0; i--)
    {
        heapify(ans, size, i);
    }

    return ans;
}