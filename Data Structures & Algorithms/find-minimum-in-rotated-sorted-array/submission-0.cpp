class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int result = nums[r];
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] > result) {
                l = m + 1;
            } else {
                r = m - 1;
                result = nums[m];
            }
        }
        return result;
    }
};