#include <iostream>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> nums2;
        for(int i = 0; i < nums.size(); i++) {
            int exists = nums2[nums[i]];
            if (exists != 0){
                return true;
            }
            nums2[nums[i]] = 1;
        }
        for (const auto& pair : nums2) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
        return false;
    }
};