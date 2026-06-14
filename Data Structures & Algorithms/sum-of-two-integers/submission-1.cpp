class Solution {
public:
    int getSum(int a, int b) {
        int total = 0;
        int carry = 0;
        while(b != 0){
            // getting last bit from a and b
            int curr_sum = a ^ b;
            carry = (a & b) << 1;
            a = curr_sum;
            b = carry;
        }
        return a;
    }
};
