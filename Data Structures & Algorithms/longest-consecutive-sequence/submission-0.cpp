class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto num : nums) {
            s.insert(num);
        }        
        int maxCount = 0;
        for (int i = 0; i < nums.size(); i++) {
            // find start of sequence
            if (s.contains(nums[i]-1)) continue;
            int start = nums[i];
            int count = 0;
            while (s.contains(start++)) {
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
