class Solution {
public:
    int missingNumber(vector<int>& nums) {
        uint32_t s = 0;
        for (int i = 0; i < nums.size()+1; i++) {
            s ^= i;
        }
        for (int i = 0; i < nums.size(); i++) {
            s ^= nums[i];
        }
        return s;
    }
};
