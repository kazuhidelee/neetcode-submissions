class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<long long> rooms(n, 0);
        // sort by end -> room number
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> busy;
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> available;
        for(int i = 0; i < n; ++i){
            available.push(i);
        }
        for(vector<int> meeting: meetings){
            long long start = meeting[0];
            long long end = meeting[1];
            while(!busy.empty() && busy.top().first <= start){
                available.push(busy.top().second);
                busy.pop();
            }

            if(available.size() > 0){
                busy.push({end, available.top()});
                rooms[available.top()]++;
                available.pop();
            }else{
                auto [endTime, room] = busy.top();
                long long duration = end - start;
                long long new_start = endTime;
                long long new_end = new_start + duration; 
                busy.pop();
                busy.push({new_end, room});
                rooms[room]++;
            }
            
        }

        long long ans = 0;
        for(int i = 1; i < n; ++i){
            if(rooms[i] > rooms[ans]){
                ans = i;
            }
        }

        return ans;
    }
};