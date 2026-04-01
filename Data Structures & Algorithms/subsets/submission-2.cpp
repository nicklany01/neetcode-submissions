class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> path;
        // make a helper lambda function
        function<void(int)> backtrack = [&](int i) {
            // base case: if we've hit the max path
            if (i == nums.size()) {
                subsets.push_back(path);
                return;
            }

            // decision 1: add the next index of nums to the path
            path.push_back(nums[i]);
            backtrack(i + 1);

            // devision 2: don't add the next index of nums to the path
            path.pop_back();
            backtrack(i + 1);
            return;
        };
        backtrack(0);
        return subsets;
    }
};
