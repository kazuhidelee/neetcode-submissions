class LFUCache {
public:
    struct Node{
        int key;
        int val;
        int count = 0;
        Node* prev;
        Node* next;
        Node(int in_key, int in_val){
            key = in_key;
            val = in_val;
        }
        Node(int in_key, int in_val, int in_freq){
            key = in_key;
            val = in_val;
            count = in_freq;
        }
    };

    struct Dll{
        Node* lru;
        Node* mru; 
        int size = 0;
        Dll(){
            lru = new Node(0,0);
            mru = new Node(0,0);
            mru->next = lru;
            lru->prev= mru;
        }
    };

    unordered_map<int, Node*> nodes;
    unordered_map<int, Dll> lists; 
    int min_freq = 1;
    int cap;
    int size = 0;

    LFUCache(int capacity) {
        cap = capacity;
    }

    void remove(int key, int freq){
        Node* prev = nodes[key]->prev;
        Node* next = nodes[key]->next;

        prev->next = next;
        next->prev = prev;

        nodes.erase(key);
        lists[freq].size--;
        size--;
    }
    void insert(int freq, int key, int val){
        Node* new_node = new Node(key, val, freq);
        nodes[key] = new_node;
        Node* next = lists[freq].mru->next;
        lists[freq].mru->next = new_node;
        new_node->prev = lists[freq].mru;
        new_node->next = next;
        next->prev = new_node;
        lists[freq].size++;
        size++;  
    }
    void evict(){
        Node* to_remove = lists[min_freq].lru->prev;
        Node* prev = to_remove->prev;
        prev->next = lists[min_freq].lru;
        lists[min_freq].lru->prev = prev;
        lists[min_freq].size--;
        nodes.erase(to_remove->key);
        size--;
    }

    int get(int key) {
        if(!nodes.count(key)) return -1;
        int freq = nodes[key]->count;
        int val = nodes[key]->val; 
        if(freq == min_freq && lists[freq].size == 1){
            min_freq++;
        }
        remove(key, freq);
        insert(freq + 1, key, val);

        return val;
    }
    
    void put(int key, int value) {
        if(nodes.count(key)){
            int freq = nodes[key]->count;
            if(freq == min_freq && lists[freq].size == 1){
                min_freq++;
            }
            remove(key, freq);
            insert(freq + 1, key, value);
        }else{
            if(cap == size){
                evict();
            }
            insert(1, key, value);
            min_freq = 1;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */