class Solution {
public:
    bool backtracking(int target, vector<int>& matchsticks, int index, vector<int> &side){
        if(index == matchsticks.size()) return true;

        for(int j = 0; j < 4; ++j){
            if(side[j] + matchsticks[index] <= target){
                side[j] += matchsticks[index];
                if(backtracking(target, matchsticks, index + 1, side)){
                    return true;
                }
                side[j] -= matchsticks[index];
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
        vector<int> side(4, 0);
        
        return backtracking(target, matchsticks, 0, side);
    }
};