class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if(exp < 0) {
            x = 1/x;
            exp = -exp;
        }
        double res = 1;
        double base = x;
        while(exp > 0){
            if(exp % 2 != 0){
                res *= base;
            }
            exp /= 2;
            base *= base;
        }
        return res;
    }
};
