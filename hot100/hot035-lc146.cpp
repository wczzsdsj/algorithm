#include <bits/stdc++.h>
using namespace std;

// LRU 缓存
class LRUCache {
  private:
    struct Node {
        int key;
        int value;
        Node *prev, *next;
        Node(int _key, int _value)
            : key(_key), value(_value), prev(nullptr), next(nullptr) {}
    };
    int size;
    int capacity;
    unordered_map<int, Node *> mp;
    Node *head;
    Node *tail;

    void removeNode(Node *p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    void addToHead(Node *p) {
        p->next = head->next;
        p->prev = head;
        head->next->prev = p;
        head->next = p;
    }

  public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;
        Node *p = mp[key];
        removeNode(p);
        addToHead(p);
        return p->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node *p = mp[key];
            removeNode(p);
            p->value = value;
            addToHead(p);
        } else {
            Node *p = new Node(key, value);
            mp[key] = p;
            addToHead(p);
            size++;
            if (size > capacity) {
                mp.erase(tail->prev->key);
                removeNode(tail->prev);
                size--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */