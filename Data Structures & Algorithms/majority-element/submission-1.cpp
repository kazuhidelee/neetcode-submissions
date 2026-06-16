class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;
        for(int i: nums){
            if(i == candidate){
                count++;
            }else{
                if(count == 0){
                    candidate = i;
                    count = 1;
                }else{
                    count--;
                }
            }
        }
        return candidate;
    }
};