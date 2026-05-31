class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(true){
            seen.insert(n);
            int s = 0;
            while(n > 0){
                s += pow(n % 10, 2);
                n /= 10;
            }
            if(s == 1) return true;
            if(seen.count(s)) return false;
            n = s;
        }
        return false;
        
    }
};
