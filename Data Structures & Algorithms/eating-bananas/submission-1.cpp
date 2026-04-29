class Solution {
public:
    bool verifier(vector<int>& piles, int h, int n){
        int total = 0;
        for(int p: piles){
            total += ceil((double)p/n);
        }
        if(total <= h){
            cout << n << " : true" << " total: " << total << endl;
        }else{
            cout << n << " : false" << " total: " << total  << endl;
        }
        
        return total <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int min_amount = 1;
        int max_amount = -1;
        for(int p: piles){
            max_amount = max(max_amount, p);
        }
        int res = 0;
        while(min_amount <= max_amount){
            int mid = (min_amount + max_amount)/2;
            if(verifier(piles, h, mid)){
                res = mid;
                max_amount = mid - 1;
            }else{
                min_amount = mid + 1;
            }
        }
        return res;
    }
};
