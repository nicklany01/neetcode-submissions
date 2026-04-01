class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zeroIndex = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                prod *= nums[i];
            } else if (nums[i] == 0 && zeroIndex == -1) {
                zeroIndex = i;
            } else {
                return vector<int>(nums.size(), 0);
            }
        }
        vector<int> result(nums.size(),0);
        if (zeroIndex != -1) {
            result[zeroIndex] = prod;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                result[i] = prod / nums[i];
            }
        }
        return result;
    }
};
