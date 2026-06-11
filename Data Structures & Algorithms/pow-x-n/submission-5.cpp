class Solution {
public:
    double myPow(double x, int n) {
        if(n < 0) {
            x = 1/x;
            n = -n;
        }
        double res = 1;
        double base = x;
        while(n > 0){
            if(n % 2 != 0){
                res *= base;
            }
            n /= 2;
            base *= base;
        }
        return res;
    }
};
