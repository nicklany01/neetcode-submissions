class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i])-1] < 0) return abs(nums[i]);
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = -nums[i];
        }
        return 0;
    }
};
