class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    int cap ;
    map<int,node*>mp;
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->next = head;
    }
    void addnode(node* addn){
        node* temp = head->next;
        addn->next = temp;
        addn->prev = head;
        head->next = addn;
        temp->prev = addn;
    }
    void delnode(node* deln){
        node* delprev = deln->prev;
        node* delnxt = deln->next;
        delprev->next = delnxt;
        delnxt->prev = delprev;

    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node * callednode = mp[key];
            int val = callednode->val;
            mp.erase(key);
            delnode(callednode);
            addnode(callednode);
            // mp[key]= head->next;
            mp[key] = callednode;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* resnode = mp[key];
            mp.erase(key);
            delnode(resnode);
        }
        else if(mp.size()==cap){
            node* lru = tail->prev;
            mp.erase(lru->key);
            delnode(lru);
        }
        addnode(new node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */