class List{
    public:
    int key;
    int val; 
    List* next;
    List(int in_key, int in_val){
        key = in_key;
        val = in_val;
        next = nullptr;
    }
};

class MyHashMap {
public:
    const int BUCKET_SIZE = 10000;
    vector<List*> buckets;
    MyHashMap() {
        for(int i = 0; i < BUCKET_SIZE; ++i){
            buckets.push_back(nullptr);
        }
    }
    
    void put(int key, int value) {
        int hash_key = key % 10000;
        List* ptr = buckets[hash_key];
        List* node = new List(key, value);
        while(ptr){
            if(ptr->key == key){
                ptr->val = value;
                return;
            }
            ptr = ptr->next;
        }
        node->next = buckets[hash_key];
        buckets[hash_key] = node;
    }
    
    int get(int key) {
        int hash_key = key % 10000;
        List* ptr = buckets[hash_key];
        while(ptr){
            if(ptr->key == key){
                return ptr->val;
            }
            ptr = ptr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_key = key % 10000;
        List* ptr = buckets[hash_key];
        List* prev = nullptr;
        while(ptr){
            if(ptr->key == key){
                if(prev){
                    prev->next = ptr->next;
                }else{
                    buckets[hash_key] = ptr->next;
                }
                delete ptr;
                return;
            }
            prev = ptr;
            ptr = ptr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */