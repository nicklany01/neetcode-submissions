class Solution {
public:
    int missingNumber(vector<int>& nums) {
        uint32_t s = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            s ^= i;
            s ^= nums[i];
        }
        return s;
    }
};
