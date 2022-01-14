#include<iostream>
#include<vector>
using namespace std;

int main()
{
    cout << "Representation_and_Storing_Of_DSA_And_Graph.cpp";


    cout << "Hello World!";
    int n = 3;
    int m = 3;


    // 1st way -> using Adjecency Matrix
    int adj[4][4];


    adj[1][3] = 1;
    adj[2][1] = 1;

    // 2nd way -> using Adjecency List
    vector<int> adjList[4];

    // adge 1-->2
    adjList[1].push_back(2);
    adjList[2].push_back(1);

    // 2--> 3
    adjList[2].push_back(3);
    adjList[3].push_back(2);


    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i][j] << " " << endl;
        }
        cout << endl;
    }


    return 0;
}

