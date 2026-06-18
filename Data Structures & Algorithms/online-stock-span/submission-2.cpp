class StockSpanner {
public:
    // value, num
    stack<pair<int, int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int num = 1;
        while(!s.empty() && s.top().first <= price){
            num += s.top().second;
            s.pop();
        }
        s.push({price, num});
        return num;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */