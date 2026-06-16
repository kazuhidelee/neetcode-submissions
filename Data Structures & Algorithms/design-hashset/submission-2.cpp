class List{
public:
    int val;
    List* next;
    List(int val_in){
        val = val_in;
        next = nullptr;
    }
};

class MyHashSet {
public:
    const int NUM_BUCKET = 10000;
    vector<List*> buckets;
    MyHashSet() {
        for(int i = 0; i < NUM_BUCKET; ++i){
            buckets.push_back(nullptr);
        }
    }
    
    void add(int key) {
        if(contains(key)) return;
        int hash_key = key % NUM_BUCKET;
        List* node = new List(key);
        node->next = buckets[hash_key];
        buckets[hash_key] = node;
    }
    
    void remove(int key) {
        int hash_key = key % NUM_BUCKET;
        List* ptr = buckets[hash_key];
        List* prev = nullptr;
        while(ptr){
            if(ptr->val == key){
                if(!prev){
                    buckets[hash_key] = ptr->next;
                }else{
                    prev->next = ptr->next;
                }
                delete ptr;
                return;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
    
    bool contains(int key) {
        int hash_key = key % NUM_BUCKET;
        List* ptr = buckets[hash_key];
        while(ptr){
            if(ptr->val == key) return true;
            ptr = ptr->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */