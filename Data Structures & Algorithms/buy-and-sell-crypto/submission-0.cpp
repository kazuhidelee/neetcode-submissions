class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_sofar = INT_MAX;
        int max_prof = 0;
        for(int i: prices){
            min_sofar = min(min_sofar, i);
            max_prof = max(i - min_sofar, max_prof);
        }
        return max_prof;
    }
};
