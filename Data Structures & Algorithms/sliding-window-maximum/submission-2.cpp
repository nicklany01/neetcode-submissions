class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // if window is too big
        if (nums.size() <= k) {
            k = nums.size();
            cerr << k << endl;
        }
        int l = 0, r = k - 1;
        priority_queue<pair<int,int>> pq;
        vector<int> result;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i],i});
        }
        while (r < nums.size()) {
            pq.push({nums[r],r});
            while (pq.top().second < l) {
                pq.pop();
            }
            result.push_back(pq.top().first);
            l++;
            r++;
        }
        return result;
    }
};
