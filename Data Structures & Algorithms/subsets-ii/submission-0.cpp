class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        function<void(int)> backtrack = [&](int i) {
            // base case: if we've searched all of it
            if (i == nums.size()) {
                result.push_back(path);
                return;
            }
            // either include or skip (skip until number is different)
            path.push_back(nums[i]);
            backtrack(i + 1);
            path.pop_back();
            while (nums[i] == nums[i+1]) {
                i++;
            }
            backtrack(i + 1);
        };
        backtrack(0);
        return result;
    }
};