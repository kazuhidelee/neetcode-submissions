class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> new_array;
        int i = 0;
        int j = 0;
        while(i < nums1.size() || j < nums2.size()){
            if(i < nums1.size() && j < nums2.size()){
                cout << "[1] " << "i: " << i << " j: " << j << endl;
                if(nums1[i] < nums2[j]){
                    new_array.push_back(nums1[i]);
                    ++i;
                }else{
                    new_array.push_back(nums2[j]);
                    ++j;
                }
            }else if(i < nums1.size()){
                cout << "[2] " << "i: " << i << " j: " << j << endl;
                new_array.push_back(nums1[i]);
                ++i;
            }else if(j < nums2.size()){
                cout << "[3] " << "i: " << i << " j: " << j << endl;
                new_array.push_back(nums2[j]);
                ++j;
            }
        }
        if(new_array.size() % 2 == 0){
            cout << new_array.size() << endl;
            return (new_array[new_array.size()/2] + new_array[new_array.size()/2 - 1]) / 2.0;
        }else{
            return new_array[new_array.size()/2];
        }
    }
};
