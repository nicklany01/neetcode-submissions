class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.size()); // set size to avoid rehashing
        for (auto num : nums) {
            s.insert(num);
        }        
        int maxCount = 0;
        for (int num : s) { // loops over set not nums
            // find start of sequence
            if (s.contains(num-1)) continue;
            int start = num;
            int count = 0;
            while (s.contains(start++)) {
                count++;
            }
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
