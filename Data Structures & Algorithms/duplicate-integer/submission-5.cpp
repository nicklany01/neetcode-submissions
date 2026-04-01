#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> c;
        for (auto num : nums) {
            if (c[num] > 0) return true;
            c[num]++;
        }
        return false;
    }
};