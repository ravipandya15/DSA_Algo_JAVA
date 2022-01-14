#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "CN_Quick_Sort";
    return 0;
}

int partition(vector<int>& arr, int s, int e)
{
    int pivot = arr[s];

    //count no. of element which are smaller than or equal to s;
    int count = 0;
    for (int index = s + 1; index <= e; index++)
    {
        if (arr[index] <= pivot) count++;
    }

    //find proper index;
    int pivotIndex = s + count;

    // swap
    swap(arr[s], arr[pivotIndex]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            // swap
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void solve(vector<int>& arr, int s, int e)
{
    if (s >= e) return;

    //do partition
    int p = partition(arr, s, e);

    // Sort left part
    solve(arr, s, p - 1);

    // Sort right part
    solve(arr, p + 1, e);
}

vector<int> quickSort(vector<int> arr)
{
    solve(arr, 0, arr.size() - 1);
    return arr;
}