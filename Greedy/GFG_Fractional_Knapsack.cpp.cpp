#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    return 0;
}

struct Item{
    int value;
    int weight;
};

static bool comparator(Item i1, Item i2)
{
    double r1 = (double)i1.value / (double)i1.weight;
    double r2 = (double)i2.value / (double)i2.weight;

    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, comparator); 

    int curWeight = 0; 
    double finalvalue = 0.0; 
    
    
    for (int i = 0; i < n; i++) {
        
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
        }
    

        else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }
    
    return finalvalue;
}