class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev_hold = prices[0] * -1;
        int prev_cash = 0;
        for(int i = 1; i < prices.size(); ++i){
            // if we decide to hold it
            int hold = max(prev_hold, prev_cash - prices[i]);
            // if we decide to cash out
            int cash = max(prev_cash, prev_hold + prices[i]);
            prev_cash = cash;
            prev_hold = hold;
        }
        return prev_cash;
    }
};