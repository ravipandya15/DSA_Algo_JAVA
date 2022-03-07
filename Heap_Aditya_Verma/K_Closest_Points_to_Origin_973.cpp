#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    return 0;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, pair<int, int>>> maxi; // max heap is required

    for (int i = 0; i < points.size(); i++)
    {
        maxi.push( { points[i][0] * points[i][0] + points[i][1] * points[i][1] ,
                    { points[i][0], points[i][1] }
                 });
        if (maxi.size() > k)
        {
            maxi.pop();
        }
    }

    vector<vector<int>> ans;
    while (maxi.size() > 0)
    {
        pair<int, int> p = maxi.top().second;
        vector<int> temp;
        temp.push_back(p.first);
        temp.push_back(p.second);
        ans.push_back(temp);

        maxi.pop();
    }

    return ans;
}