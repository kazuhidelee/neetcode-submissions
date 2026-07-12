class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        for(string ops: operations){
            if(ops == "+"){
                int prev1 = records.top();
                records.pop();
                int prev2 = records.top();
                records.pop();
                int sum12 = prev1 + prev2;
                records.push(prev2);
                records.push(prev1);
                records.push(sum12);
                // cout << "adding: " << prev1 << endl;
                // cout << "adding: " << prev2 << endl;
                // cout << "adding: " << sum12 << endl;
            }else if(ops == "D"){
                int prev = records.top();
                records.push(prev * 2);
                // cout << "doubling: " << prev * 2 << endl;
            }else if(ops == "C"){
                // cout << "delete: " << records.top() << endl;
                if(!records.empty()) records.pop();
            }else{
                // cout << "insert: " << ops << endl;
                records.push(stoi(ops));
            }
        }
        int res = 0;
        while(!records.empty()){
            cout << records.top() << endl;
            res += records.top();
            records.pop();
        }
        return res;
    }
};