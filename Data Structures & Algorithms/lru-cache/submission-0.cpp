class LRUCache {
public:
    struct ListNode{
        int key;
        int val;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
        ListNode() : key(0), val(0), next(nullptr), prev(nullptr) {}
        ListNode(int key_in, int val_in) : key(key_in), val(val_in), next(nullptr), prev(nullptr) {}
    };
    int cap;
    int curr_size;
    unordered_map<int, ListNode*> mapping;
    // left
    ListNode* mru = new ListNode(0, 0);
    // right
    ListNode* lru = new ListNode(0, 0);

    LRUCache(int capacity) {
        cap = capacity;
        curr_size = 0;
        mru->next = lru;
        lru->prev = mru;
    }

    void add_key(int key, int value){
        mapping[key] = new ListNode(key, value);
        ListNode* temp = mru->next;
        mru->next = mapping[key];
        mapping[key]->prev = mru;
        mapping[key]->next = temp;
        temp->prev = mapping[key];
        curr_size++;
    }
    void remove_key(int key){
        ListNode* prev_node = mapping[key]->prev;
        ListNode* next_node = mapping[key]->next;
        delete mapping[key];
        mapping.erase(key);
        prev_node->next = next_node;
        next_node->prev = prev_node;
        curr_size--;
    }

    void del_key(){
        ListNode* prev_node = lru->prev->prev;
        mapping.erase(lru->prev->key);
        delete lru->prev;
        prev_node->next = lru;
        lru->prev = prev_node;
        curr_size--;
    }
    
    int get(int key) {
        if(mapping.count(key)){
            int value = mapping[key]->val;
            remove_key(key);
            add_key(key, value);
            return mapping[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mapping.count(key)){
            remove_key(key);
            add_key(key, value);
            mapping[key]->val = value;
            return;
        }
        if(curr_size == cap){
            del_key();
            add_key(key, value);
        }else{
            add_key(key, value);
        }
    }
};
