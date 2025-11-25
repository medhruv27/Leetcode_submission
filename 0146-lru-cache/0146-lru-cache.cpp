class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
    };
    int cap;
    map<int ,node*>mp;
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* resnode){
        node* temp = head->next;
        resnode->next = temp;
        resnode->prev = head;
        head->next = resnode;
        temp->prev = resnode;
    }

    void delnode(node* resnode){
        node* delnxt = resnode->next;
        node* delprev = resnode->prev;
        delprev->next = delnxt;
        delnxt->prev = delprev;
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            node* resnode = mp[key];
            int res = resnode->val;
            mp.erase(key);
            delnode(resnode);
            addnode(resnode);
            mp[key]= head->next;
            return res;
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
        addnode(new node(key, value));
        mp[key] = head->next;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */