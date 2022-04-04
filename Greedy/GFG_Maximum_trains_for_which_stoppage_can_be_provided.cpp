#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// CN ma pan chhe

bool compare(vector<int> t1, vector<int> t2)
{
    return t1[1] < t2[1];
}

class Item
{
    public:
        int arrivalTime;
        int departureTime;
        int plateformNumber;

        Item(int aTime, int dTime, int pNum)
        {
            this->arrivalTime = aTime;
            this->departureTime = dTime;
            this->plateformNumber = pNum;
        }
};

bool compare2(Item* i1, Item* i2)
{
    if (i2->departureTime == i1->departureTime)
    {
        return i2->arrivalTime < i1->arrivalTime;
    }
    return i2->departureTime <i1->departureTime;
}

int maxStop(vector<vector<int>> &trains, int n, int m)
{
    vector<int> v(n+1, -1);
    vector<Item*> items;

    for (int i = 0; i < trains.size(); i++)
    {
        Item* item = new Item(trains[i][0], trains[i][1], trains[i][2]);
        items.push_back(item);
    }

    sort(items.begin(), items.end(), compare2);

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        if (v[items[i]->plateformNumber] == -1)
        {
            count++;
            v[items[i]->plateformNumber] = i;
        }
        else
        {
            if ( items[v[items[i]->plateformNumber]]->departureTime <= items[i]->arrivalTime)
            {
                count++;
                v[items[i]->plateformNumber] = i;
            }
        }
    }

    return count;
}

int maxStop_1(vector<vector<int>> &trains, int n, int m)
{
    vector<int> v(n+1, -1);

    sort(trains.begin(), trains.end(), compare);

    int count = 0;

    for (int i = 0; i < m; i++)
    {
        if (v[trains[i][2]] == -1)
        {
            count++;
            v[trains[i][2]] = i;
        }
        else
        {
            if ( trains[v[trains[i][2]]][1] <= trains[i][0])
            {
                count++;
                v[trains[i][2]] = i;
            }
        }
    }

    return count;
}

int main()
{
    
    return 0;
}
