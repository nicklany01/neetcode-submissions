class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        // make a helper lambda function
        function<void(int,vector<int>)> backtrack = [&](int i, vector<int> path) {
            // base case: if we've hit the max path
            if (i == nums.size()) {
                subsets.push_back(path);
                return;
            }

            // devision 1: don't add the next index of nums to the path
            backtrack(i + 1, path);

            // decision 2: add the next index of nums to the path
            path.push_back(nums[i]);
            backtrack(i + 1, path);
            return;
        };
        backtrack(0, {});
        return subsets;
    }
};
