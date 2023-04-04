// Question link
// https://practice.geeksforgeeks.org/problems/lru-cache/0

#include <bits/stdc++.h>
using namespace std;


class LRUCache
{
    private:
    
    public:
    
    class node 
    {
        public:
        int key, val;
        node *prev, *next;
        node(int key_,int val_)
        {
            key = key_;
            val = val_;
            prev=next=NULL;
        }
    };
    
    int capacity;
    unordered_map<int, node*> m;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
        capacity = cap;
        
        head->next = tail;
        tail->prev = head;
        tail->next = head->prev = NULL;
        
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(m.find(key) != m.end())
        {
            node *addr = m[key];
            int value = addr->val;
            
            
            addr->prev->next = addr->next;
            addr->next->prev = addr->prev;
            delete addr;
            
            node *n = new node(key, value);
            n->next = head->next;
            head->next->prev = n;
            head->next = n;
            n->prev = head;
            m[key] = n;
            
            return value;
        }
        else
            return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here   
        if(m.find(key) != m.end())
        {
            node *addr = m[key];
            addr->prev->next = addr->next;
            addr->next->prev = addr->prev;
            delete addr;
            
            node *n = new node(key, value);
            n->next = head->next;
            head->next->prev = n;
            head->next = n;
            n->prev = head;
            m[key] = n;
        }
        else if(m.size() == capacity)
        {
            node *n = tail->prev;
            int key_ = n->key;
            n->prev->next = tail;
            tail->prev = n->prev;
            m.erase(key_);
            delete n;
            
            node *nw = new node(key, value);
            nw->next = head->next;
            head->next->prev = nw;
            head->next = nw;
            nw->prev = head;
            m[key] = nw;
        }
        else
        {
            
            
            node *n = new node(key, value);
            n->next = head->next;
            head->next->prev = n;
            head->next = n;
            n->prev = head;
            m[key] = n;
            
            
        }
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends