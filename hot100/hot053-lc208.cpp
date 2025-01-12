#include <bits/stdc++.h>
using namespace std;

// 208. 实现 Trie (前缀树)
class Trie {
  private:
    vector<Trie *> chilldren;
    bool isend;

    Trie *searchPrefix(string word) {
        Trie *node = this;
        for (auto c : word) {
            int index = c - 'a';
            if (node->chilldren[index] == nullptr)
                return nullptr;
            node = node->chilldren[index];
        }
        return node;
    }

  public:
    Trie() : chilldren(26), isend(false) {}

    void insert(string word) {
        Trie *node = this;
        for (auto c : word) {
            int index = c - 'a';
            if (node->chilldren[index] == nullptr)
                node->chilldren[index] = new Trie();
            node = node->chilldren[index];
        }
        node->isend = true;
    }

    bool search(string word) {
        Trie *node = searchPrefix(word);
        return node != nullptr && node->isend == true;
    }

    bool startsWith(string prefix) {
        Trie *node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */