class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++; 
        }
        // group numbers by frequency
        vector<vector<int>> buckets(nums.size()+1);
        for (auto [num, f] : freq) {
            buckets[f].push_back(num);
        }
        // collect highest frequency nums
        vector<int> result;
        for (int i = nums.size(); result.size() < k && i >= 0; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
            }
        }
        return result;
    }
};
