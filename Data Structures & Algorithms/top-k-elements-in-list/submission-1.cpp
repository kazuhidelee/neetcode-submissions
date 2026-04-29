class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1, vector<int>());
        unordered_map<int, int> freq;
        for(int i: nums){
            freq[i]++;
        }

        for(auto f: freq){
            buckets[f.second].push_back(f.first);
        }
        vector<int> res;
        for(int i = nums.size(); i > 0; --i){
            if(buckets[i].size() > 0){
                for(int j = 0; j < buckets[i].size(); ++j){
                    res.push_back(buckets[i][j]);
                    --k;
                }
            }
            if(k == 0){
                break;
            }
        }
        return res;
    

    }
};
