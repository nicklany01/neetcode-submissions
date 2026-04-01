class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;
        sort(intervals.begin(), intervals.end());
        int i = 1;
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        while (i < intervals.size()) {
            if (result.back()[1] < intervals[i][0]) {
                result.push_back(intervals[i]);
            } else {
                result.back()[0] = min(result.back()[0], intervals[i][0]);
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            }
            i++;
        }
        return result;
    }
};
