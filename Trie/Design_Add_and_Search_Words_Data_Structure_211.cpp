#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Trie Approach
class WordDictionary {

public:
    struct Trie{
        Trie* child[26];
        bool isEnd = false;
    };

    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie* cur = root;
        for (auto &ch : word)
        {
            int pos = ch - 'a';
            if (cur->child[pos] == NULL) cur->child[pos] = new Trie();
            cur = cur->child[pos];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        Trie* cur = root;
        return find(word, 0, cur);
    }

    bool find(string &word, int ind, Trie* cur)
    {
        if (ind == word.size()) return cur->isEnd;

        if (word[ind] == '.')
        {
            // check every posibility
            for (int i = 0; i < 26; i++)
            {
                if (cur->child[i] && find(word, ind + 1, cur->child[i])) return true;
            }
        }
        else
        {
            int i = word[ind] - 'a';
            if (cur->child[i] && find(word, ind + 1, cur->child[i])) return true;
        }
        return false;
    }
};

// it gives TLE
// HashMap Approach
class WordDictionary1 {
private:
unordered_map<int, vector<string>> map;
bool isEqual(string a, string b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (b[i] == '.') continue;
        if (a[i] != b[i]) return false;
    }
    return true;
}
public:
    WordDictionary1() {
        
    }
    
    void addWord(string word) {
        map[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for (auto s : map[word.size()])
        {
            if (isEqual(s, word)) return true;
        }
        return false;
    }
};