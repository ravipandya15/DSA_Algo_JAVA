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

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie {

private: Node* root;

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
        }

        node->setEnd();  
    }

    bool checkIfAllPrefixExists(string word)
    {
        Node* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if (node->isEnd() == false) return false;
            }
            else
            {
                return false;
            }
        }

        return true;
    } 
};

string completestring(int n, vector<string> &a){
    Trie* trie = new Trie();
    for (string it : a)
    {
        trie->insert(it);
    }

    string longest = "";
    for (string it : a)
    {
        if (trie->checkIfAllPrefixExists(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }

    if (longest == "") return "None";
    return longest;
}