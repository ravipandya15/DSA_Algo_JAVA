#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
    Node* links[2];

    bool containesKey(int bit)
    {
        return (links[bit] != NULL);
    }

    Node* get(int bit)
    {
        return links[bit];
    }

    void put(int bit, Node* node)
    {
        links[bit] = node;
    }
};

class Trie
{
    private:    
    Node* root;

    public:
    Trie()
    {
        root = new Node();
    }

    public:
    void insert(int num)
    {
        Node* node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containesKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    public:
    int getMax(int num)
    {
        Node* node = root;
        int max = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containesKey(1 - bit))
            {
                max = max | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return max;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
    vector<int> ans(queries.size());
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> offlineQueries;

    int index = 0;
    for (auto& it : queries)
    {
        offlineQueries.push_back({it[1], {it[0], index++}});
    }

    sort(offlineQueries.begin(), offlineQueries.end());

    int i = 0;
    int n = arr.size();
    
    Trie trie;

    for (auto& it : offlineQueries)
    {
        while (i < n && arr[i] <= it.first)
        {
            trie.insert(arr[i]);
            i++;
        }
        
        if (i != 0)
        {
            ans[it.second.second] = trie.getMax(it.second.first);
        }
        else
        {
            ans[it.second.second] = -1;
        }
    }

    return ans;
}