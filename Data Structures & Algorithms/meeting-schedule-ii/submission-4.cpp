/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts(intervals.size(),0);
        vector<int> ends(intervals.size(),0);
        for (int i = 0; i < intervals.size(); i++) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int rooms = 0;
        int maxRooms = 0;
        int s = 0, e = 0;
        while (s < intervals.size()) {
            if (starts[s] < ends[e]) {
                s++;
                rooms++;
            } else {
                e++;
                rooms--;
            }
            cout << rooms << endl;
            maxRooms = max(maxRooms, rooms);
        }
        return maxRooms; 
    }
};
