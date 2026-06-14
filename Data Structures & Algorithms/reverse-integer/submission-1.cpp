class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            if(res >= INT_MAX / 10.0 || res <= INT_MIN / 10.0) return 0;
            res *= 10;
            res += x % 10;
            x /= 10;
        }
        if(res <= INT_MIN || res >= INT_MAX) return 0;
        return res;
    }
};
