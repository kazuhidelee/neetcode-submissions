class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ptr = 0;
        int min_diff = INT_MAX;
        for(int i = 0; i < arr.size(); ++i){
            if(abs(arr[i] - x) < min_diff){
                ptr = i;
                min_diff = abs(arr[i] - x);
            }
        }
        int l = ptr;
        int r = ptr;
        while(r - l + 1 < k){
            if(r + 1 < arr.size() && l - 1 >= 0){
                if(abs(arr[r + 1] - x) < abs(arr[l - 1] - x)){
                    ++r;
                }else{
                    --l;
                }
            }else{
                if(r + 1 < arr.size()) r++;
                if(l - 1 >= 0) --l;
            }
        }
        vector<int> res;
        for(int i = l; i <= r; ++i){
            res.push_back(arr[i]);
        }
        return res;

    }
};