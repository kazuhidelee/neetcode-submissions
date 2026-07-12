class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size() - k;
        while(l < r){
            int m = (l + r) / 2;
            if (x - arr[m] > arr[m + k] - x){
                l = m + 1;
            }else{
                r = m;
            }
        }
        vector<int> res;
        for(int i = l; i < l + k; ++i){
            res.push_back(arr[i]);
        }
        return res;

    }
};