#include<vector>
#include<iostream>
using namespace std;

struct Node
{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    Node* get(char ch)
    {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int n = s.length();
    Node* root = new Node();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        Node* node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(s[j]))
            {
                count++;
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return count + 1;
}