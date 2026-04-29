class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int res = 0;
        unordered_map<char, int> freq;
        priority_queue<int> pq;
        queue<pair<int, int>> used;
        for(char c: tasks){
            freq[c]++;
        }
        for(auto f: freq){
            pq.push({f.second});
        }
        int time = 0;
        while(!pq.empty() || !used.empty()){
            time++;
            
            if(!pq.empty()){
                int curr = pq.top(); 
                pq.pop();
                if (curr - 1 > 0) {
                    used.push({curr - 1, time + n});
                }
            }else{
                time = used.front().second;
            }
            if(!used.empty() && used.front().second <= time){
                pq.push({used.front().first});
                used.pop();
            }

        }
        return time;
    }
};
