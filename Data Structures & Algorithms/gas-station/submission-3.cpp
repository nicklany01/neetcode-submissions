class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // find the local optimal solution
        // maximise the amount you can travel, i.e. gas[i] - cost[i]
        // at each iteration it goes up or down by the diff, we want to start at the lowest point in the diff
        int gasTotal = 0;
        int costTotal = 0;
        for (int i = 0; i < cost.size(); i++) {
            gasTotal += gas[i];
            costTotal += cost[i];
        }
        if (gasTotal < costTotal) return -1;
        int result = 0;
        int total = 0;
        for (int i = 0; i < cost.size(); i++) {
            int val = gas[i] - cost[i];
            total += val;
            if (total < 0) {
                total = 0;
                result = i+1;
            }
        }
        return result;
    }
};
