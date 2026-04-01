class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> elements;
        sort(candidates.begin(), candidates.end());
        function<void(int,int)> backtrack = [&](int i, int sum) {
            // base case(s)
            if (sum == target) {
                result.push_back(elements);
                return;
            }
            if (i == candidates.size()) {
                return;
            }
            // decision 1: add new element
            elements.push_back(candidates[i]);
            backtrack(i + 1, sum + candidates[i]);
            // decision 2: skip element
            while (candidates[i] == candidates[i+1] && i + 1 < candidates.size()) {
                i++;
            }
            elements.pop_back();
            backtrack(i + 1, sum);
        };
        backtrack(0,0);
        return result;
    }
};
