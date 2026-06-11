class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double ans = x;
        for(int i = 0; i < abs(n) - 1; ++i){
            ans *= x;
        }
        cout << ans;
        if(n < 0){
            ans = 1 / ans;
        }
        return ans;
    }
};
