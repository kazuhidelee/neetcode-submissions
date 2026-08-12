class MyCircularQueue {
public:
    int curr_size = 0;
    int capacity = 0;
    int front = 0;
    int rear = -1;
    vector<int> q;
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
    }
    
    bool enQueue(int value) {
        if(curr_size == capacity) return false;
        rear = (rear + 1) % capacity;
        q[rear] = value;
        curr_size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        front = (front + 1) % capacity;
        curr_size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return q[rear];
    }
    
    bool isEmpty() {
        return curr_size == 0;
    }
    
    bool isFull() {
        return curr_size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */