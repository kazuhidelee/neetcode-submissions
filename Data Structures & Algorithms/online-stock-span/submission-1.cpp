class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        for(int i = prices.size() - 1; i >= 0; --i){
            if(prices[i] <= price){
                res++;
            }else{
                break;
            }
        }
        prices.push_back(price);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */