class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort by end time
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){return a[1] < b[1];});
        int count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i-1][1] > intervals[i][0]) {
                // "erase" interval
                intervals[i][1] = intervals[i-1][1];
                count++;
            }
        }
        return count;
    }
};