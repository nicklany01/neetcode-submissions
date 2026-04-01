class Solution {
public:
    int missingNumber(vector<int>& nums) {
        uint32_t s = nums.size(); // this is to add the extra number thats going to be missing in s
        for (int i = 0; i < nums.size(); i++) {
            s ^= i; // xor each number to add it
            s ^= nums[i]; // xor the num to remove it
        }
        return s; // remaining number is in here
    }
};
