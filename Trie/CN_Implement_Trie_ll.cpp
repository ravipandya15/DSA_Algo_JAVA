#include<vector>
#include<iostream>
using namespace std;

struct Node
{
    Node* links[26];
    int countEndWith = 0;
    int countPrefix = 0;

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

    void increaseEndWith()
    {
        countEndWith++;
    }

    void increasePrefix()
    {
        countPrefix++;
    }

    void decreaseEndWith()
    {
        countEndWith--;
    }

    void decreasePrefix()
    {
        countPrefix--;
    }

    int getEnd()
    {
        return countEndWith;
    }

    int getPrefix()
    {
        return countPrefix;
    }
};

class Trie{
    private: Node* root;

    public:

    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
            node->increasePrefix();
        }

        node->increaseEndWith();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* node = root;
        for (int i =0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        for (int i =0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word){
        // Write your code here.
        Node* node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }

            node = node->get(word[i]);
            node->decreasePrefix();
        }

        node->decreaseEndWith();
    }
};
