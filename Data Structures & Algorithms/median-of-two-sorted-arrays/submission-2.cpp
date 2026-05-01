class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int target = (nums1.size() + nums2.size()) / 2;
        int counter = 0;
        int i = 0;
        int j = 0;
        int prev = 0;
        int curr = 0;
        while(counter <= target){
            prev = curr;
            if(i < nums1.size() && j < nums2.size()){
                if(nums1[i] < nums2[j]){
                    curr = nums1[i];
                    ++i;
                }else{
                    curr = nums2[j];
                    ++j;
                }
            }else if(i < nums1.size()){
                curr = nums1[i];
                ++i;
            }else if(j < nums2.size()){
                curr = nums2[j];
                ++j;
            }
            counter++;
        }
        if((nums1.size() + nums2.size()) % 2 == 0){
           return (curr + prev) / 2.0;
        }else{
            return curr;
        }
    }
};
