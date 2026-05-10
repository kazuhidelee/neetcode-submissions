class KthLargest {
public:
    priority_queue<int> pq;
    int k_th;
    KthLargest(int k, vector<int>& nums) {
        k_th = k;
        for(auto n: nums) pq.push(n);
    }
    
    int add(int val) {
        pq.push(val);
        vector<int> temp;
        for(int i = 1; i < k_th; ++i){
            temp.push_back(pq.top());
            pq.pop();
        }
        int res = pq.top();
        for(auto n: temp) pq.push(n);
        return res;

    }
};
