#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, bool> set;
        for (int i = 0; i < nums.size(); i++) {
            // check if it exists in the map, else add it
            if (set.count(nums[i]) > 0) {
                return true;
            } else {
                set[nums[i]] = true;
            }
        }
        return false;
    }
};