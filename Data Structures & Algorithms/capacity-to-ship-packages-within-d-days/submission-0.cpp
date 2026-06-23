class Solution {
public:
    bool can_ship(vector<int>& weights, int days, int cap){
        int curr_day = 1;
        int curr_cap = cap;
        for(int i: weights){
            if(curr_cap - i >= 0){
                curr_cap -= i;
            }else{
                curr_cap = cap;
                curr_cap -= i;
                ++curr_day;
            }
        }
        return days >= curr_day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int min_w = weights[0];
        int max_w = 0;
        for(int i: weights){
            min_w = max(i, min_w);
            max_w += i;
        }

        while(min_w < max_w){
            int m = (min_w + max_w) / 2;
            cout << min_w << " , " << max_w << endl;
            if(can_ship(weights, days, m)){
                max_w = m;
            }else{
                min_w = m + 1;
            }
        }
        return min_w;
    }
};