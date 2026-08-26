class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if(arr.size() == 1) return 1;
        
        if(arr.size() == 2){
            if(arr[0] == arr[1]) return 1;
            return 2;
        } 
        int comparison = arr[1] - arr[0];
        int max_sub = (arr[0] == arr[1]) ? 1 : 2;
        int l = 0;
        for(int r = 2; r < arr.size(); ++r){
            if(!(arr[r] > arr[r - 1] && comparison < 0 || arr[r] < arr[r - 1] && comparison > 0)){
               if(arr[r] == arr[r - 1]){
                l = r;
               }else{   
                l = r - 1;
               }
            }
            max_sub = max(max_sub, r - l + 1);
            comparison = arr[r] - arr[r - 1];
        }
        return max_sub;
    }
};