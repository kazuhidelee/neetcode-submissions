class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> bfs;
        bfs.push(0);
        int last_checked = 0;
        int len = s.length();
        while(!bfs.empty()){
            int curr = bfs.front();
            bfs.pop();
            if(curr == len - 1) return true;

            int min_range = max(minJump + curr, last_checked);
            int max_range = min(maxJump + curr, len - 1);
            for(int i = min_range; i <= max_range; ++i){
                if(s[i] == '0') bfs.push(i);
            }

            last_checked = max_range;
        }
        return false;
    }
};