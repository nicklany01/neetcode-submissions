#include <array>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        array<int,26> freq = {0};
        for (auto task : tasks) {
            freq[task - 'A']++;
        }
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] > 0) {
                pq.push({freq[i],i + 'A'});
            }
        }
        int i = 0;
        queue<pair<int,char>> waitingTasks;
        while (!pq.empty() || !waitingTasks.empty()) {
            if (!waitingTasks.empty()) {
                // if there is a waiting task that is ready to be run, add it to the available tasks
                if (waitingTasks.front().first < i) {
                    char task = waitingTasks.front().second;
                    pq.push({freq[task - 'A'], task});
                    waitingTasks.pop();
                }
            }
            // if there are available tasks, run them
            if (!pq.empty()) {
                pair<int,char> curr = pq.top();
                freq[curr.second - 'A']--;
                if (freq[curr.second - 'A'] > 0) {
                    waitingTasks.push({i + n,curr.second});
                }
                pq.pop();
            }
            i++;
        }
        return i;
    }
};
