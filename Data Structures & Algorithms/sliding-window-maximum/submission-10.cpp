class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.size() <= k) {
            k = nums.size();
        }
        deque<int> q;
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        int r = k;
        vector<int> result;
        result.push_back(nums[q.front()]);
        while (r < nums.size()) {
            // if element is too old, remove it
            while (!q.empty() && q.front() <= r - k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);
            result.push_back(nums[q.front()]);
            r++;
        }
        return result;
    }
};
