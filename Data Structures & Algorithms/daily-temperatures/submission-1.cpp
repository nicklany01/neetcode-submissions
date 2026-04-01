class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        // go from 2 1 2 3 , go forward adding lower values to stack, 21, 
        // once it hits higher, we pop from stack, counting how many times it pops only popping values that are lower
        // new max value is always top
        stack<pair<int,int>> s;
        s.push({0, temperatures[0]});
        for (int i = 1; i < temperatures.size(); i++) {
            while (!s.empty() && temperatures[i] > s.top().second) {
                result[s.top().first] = i - s.top().first;
                s.pop();
            }
            s.push({i, temperatures[i]});
        }
        return result;
    }
};
