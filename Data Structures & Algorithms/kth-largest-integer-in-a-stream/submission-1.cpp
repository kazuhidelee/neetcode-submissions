class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k_th;
    KthLargest(int k, vector<int>& nums) {
        k_th = k;
        for(auto n: nums){
            pq.push(n);
            if(pq.size() > k_th) pq.pop();
        } 
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k_th) pq.pop();
        return pq.top();

    }
};
