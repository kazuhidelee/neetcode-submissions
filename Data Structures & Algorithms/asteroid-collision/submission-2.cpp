class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> seen;
        for(int a: asteroids){
            if(a < 0){
                while(!seen.empty() && seen.top() > 0 && seen.top() < abs(a)){
                    seen.pop();
                }

                if(seen.empty() || seen.top() < 0){
                    seen.push(a);
                }else{
                    if(seen.top() == abs(a)){
                        seen.pop();
                    }
                }
            }else{
                seen.push(a);
            }
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