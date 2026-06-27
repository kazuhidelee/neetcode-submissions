class Solution {
public:
    bool backtracking(int curr_len, int target, vector<int>& matchsticks, int sides, unordered_set<int> &included){
        if(sides == 3) return true;
        for(int i = 0; i < matchsticks.size(); ++i){
            // alr considered
            if(included.count(i)) continue;
            if(matchsticks[i] + curr_len == target){
                included.insert(i);
                if(backtracking(0, target, matchsticks, sides + 1, included)) return true;
                included.erase(i);
            }else if(matchsticks[i] + curr_len < target){
                included.insert(i);
                if(backtracking(curr_len + matchsticks[i], target, matchsticks, sides, included)) return true;
                included.erase(i);
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int total = 0;
        sort(matchsticks.rbegin(), matchsticks.rend());
        for(int i: matchsticks){
            total += i;
        }
        if(total % 4 != 0) return false;
        int target = total / 4;
        if (matchsticks[0] > target) return false;
        unordered_set<int> included;
        
        return backtracking(0, target, matchsticks, 0, included);
    }
};