class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,bool> visited;
        for (auto num : nums) {
            visited[num] = false;
        }
        vector<vector<int>> result;
        vector<int> path;
        function<void()> backtrack = [&]() {
            // base case: if we have all the values in the set
            if (path.size() == nums.size()) {
                result.push_back(path);
                return;
            }
            // decisions, visit each node adding it to the path
            for (auto num : nums) {
                if (!visited[num]) {
                    visited[num] = true;
                    path.push_back(num);
                    backtrack();
                    visited[num] = false;
                    path.pop_back();
                }
            }
        };
        backtrack();
        return result;
    }
};
