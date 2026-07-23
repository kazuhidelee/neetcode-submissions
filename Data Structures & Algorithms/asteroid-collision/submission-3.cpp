class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> seen;
        for(int a: asteroids){
           while(!seen.empty() && seen.top() > 0 && a < 0){
                int diff = a + seen.top();
                if(diff < 0){
                    seen.pop();
                }else if(diff > 0){
                    a = 0;
                }else{
                    a = 0;
                    seen.pop();
                }
            }

            if(a != 0) seen.push(a);
        }
        vector<int> res;
        while(!seen.empty()){
            res.push_back(seen.top());
            seen.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};