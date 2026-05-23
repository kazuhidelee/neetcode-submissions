class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int prev_hold = INT_MIN;
        int prev_sold = 0;
        int prev_rest = 0;
        for(int i = 0; i < prices.size(); ++i){
            // hold
            int hold = max(prev_hold, prev_rest - prices[i]);
            // sell
            int sell = prev_hold + prices[i];
            // rest
            int rest = max(prev_rest, prev_sold);
            max_profit = max(hold, max(sell, rest));
            prev_hold = hold;
            prev_sold = sell;
            prev_rest = rest;
        }
        return max_profit;
    }
};
