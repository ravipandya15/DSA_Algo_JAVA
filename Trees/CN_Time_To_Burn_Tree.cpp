#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// getting wrong answer
// check java or C# Code -> both are correct
int main()
{
    cout << "CN_Time_To_Burn_Tree" << endl;
    return 0;
}

template <typename T>
class BinaryTreeNode 
{
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) 
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

// check java code

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // Write your code here
}