class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // i think sort by the processing time then the 
        // sort by enqueue time
        int index = 0;
        for(vector<int> &task: tasks){
            task.push_back(index);
            index++;
        }
        sort(tasks.begin(), tasks.end());
        int time = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        vector<int> res;
        int i = 0;
        while (i < tasks.size() || !pq.empty()) {
            if (pq.empty()) time = max(time, tasks[i][0]);

            while (i < tasks.size() && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            auto curr = pq.top();
            pq.pop();

            res.push_back(curr.second);
            time += curr.first;
        }
        return res;

    }
};