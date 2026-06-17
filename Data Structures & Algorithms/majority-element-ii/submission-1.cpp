class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        int candidate2 = 0;

        int count1 = 0;
        int count2 = 0;

        for(int i: nums){
            if (count1 > 0 && i == candidate1) {
                count1++;
            } else if (count2 > 0 && i == candidate2) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = i;
                count1 = 1;
            } else if (count2 == 0) {
                candidate2 = i;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }

        }
        count1 = 0;
        count2 = 0;

        for(int i: nums){
            if(i == candidate1){
                count1++;
            }else if(i == candidate2){
                count2++;
            }
        }

        vector<int> res;
        if(count1 > nums.size() / 3) res.push_back(candidate1);
        if(count2 > nums.size() / 3) res.push_back(candidate2);
        return res;

    }
};