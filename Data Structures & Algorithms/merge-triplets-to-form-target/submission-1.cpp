class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int max_first = INT_MIN;
        int max_second = INT_MIN;
        int max_third = INT_MIN;
        for(int i = 0; i < triplets.size(); ++i){
            if(triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]){
                continue;
            }
            max_first = max(max_first, triplets[i][0]);
            max_second = max(max_second, triplets[i][1]);
            max_third = max(max_third, triplets[i][2]);
        }
        if(max_first == target[0] && max_second == target[1] && max_third == target[2]){
            return true;
        }else{
            return false;
        }
    }
};
