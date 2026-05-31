class Solution {
public:
    int sos(int n){
        int s = 0;
        while(n > 0){
            s += pow(n % 10, 2);
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        int fast = sos(n);
        int slow = n;
        while(slow != fast){
            fast = sos(fast);
            fast = sos(fast);
            slow = sos(slow);
        }
        return slow == 1;
        
    }
};
