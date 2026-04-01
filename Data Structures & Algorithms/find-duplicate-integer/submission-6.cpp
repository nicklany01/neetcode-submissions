class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // use the original vector as a hashmap
        for (int i = 0; i < nums.size(); i++) {
            if (nums[abs(nums[i])-1] < 0) return abs(nums[i]);
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1];
        }
        // reset the original vector so it's not modified
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = abs(nums[i]);
        }
        return 0;
    }
};
