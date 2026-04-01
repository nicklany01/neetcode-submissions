class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // nested twosum
        sort(nums.begin(), nums.end());
        set<vector<int>> numset;

        for (int i = 0; i < nums.size(); i++) {
            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if (sum == 0) {
                    numset.insert({nums[start], nums[end], nums[i]});
                    start++;
                }
                else if (sum < 0) start++;
                else end--;
            }
        }
        return {numset.begin(), numset.end()};
    }
};
