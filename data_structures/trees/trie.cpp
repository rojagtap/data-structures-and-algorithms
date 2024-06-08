#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode* next[26];
};

class Trie {
public:
    void insert(const string word) {
        TrieNode* pointer = root;
        for (const auto& character : word) {
            if (!pointer->next[character - 'a']) {
                pointer->next[character - 'a'] = new TrieNode();
            }
            pointer = pointer->next[character - 'a'];
        }
    }

    bool exists(const string word) {
        TrieNode* pointer = root;
        for (const auto& character : word) {
            if (!pointer->next[character - 'a']) {
                return false;
            }
            pointer = pointer->next[character - 'a'];
        }

        return true;
    }

private:
    TrieNode* root = new TrieNode();
};


int main() {
    Trie trie;

    trie.insert("chair");
    cout << (bool) trie.exists("hair") << endl;
    cout << (bool) trie.exists("air") << endl;
    cout << (bool) trie.exists("chai") << endl;

    return 0;
}