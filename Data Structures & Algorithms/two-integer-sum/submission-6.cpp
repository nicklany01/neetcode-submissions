#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map1; // num, index

        for (int i = 0; i < nums.size(); i++) {
            map1[target - nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            // find if nums[i] is an index in the map 
            int ind = map1[nums[i]];
            if (ind != 0 && ind != i) {
                return vector<int> {i, ind};
            }
        }
    }
};
