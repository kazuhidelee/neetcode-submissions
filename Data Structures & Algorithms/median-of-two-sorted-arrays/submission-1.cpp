class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int total = nums1.size() + nums2.size();
        int middle = (total + 1) / 2;
        int low = 0;
        int high = nums1.size();
        while (low <= high){
            int cutA = (low + high) / 2;
            int cutB = middle - cutA;
            int leftA = (cutA == 0) ? INT_MIN : nums1[cutA - 1];
            int rightA = (cutA == nums1.size()) ? INT_MAX : nums1[cutA];

            int leftB = (cutB == 0) ? INT_MIN : nums2[cutB - 1];
            int rightB = (cutB == nums2.size()) ? INT_MAX : nums2[cutB];

            if (leftA > rightB) {
                high = cutA - 1;
            } else if (leftB > rightA) {
                low = cutA + 1;
            } else {
                if (total % 2 == 0) {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                } else {
                    return max(leftA, leftB);
                }
            }

        }
        return 0;

    }
};
