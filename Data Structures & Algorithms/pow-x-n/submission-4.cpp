class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0){
            x = 1/x;
            n = -n;
        }
        if(n % 2 == 0){
            double half = myPow(x, n / 2);
            return half * half;
        }else{
            double half = myPow(x, n / 2);
            return x * half * half;
        }
    }
};
