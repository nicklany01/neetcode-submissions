class Solution {
public:
    int jump(vector<int>& nums) {
        // locally optimal choice. each choice should get to the solution optimally.
        // in this case, if we know which hop will result in the max reach possible, we want that step
        // range represents range of indices after i that we can reach, and go through each of these to
        // see which one will allow us to reach even further
        int count = 0;
        int r = 0;
        int nextR = 0;
        // keep going right, until we hit the end of the range, then make the new range the max range we've found
        for (int i = 0; i < nums.size() - 1; i++) {
            nextR = max(nextR, i + nums[i]);
            if (i == r) {
                r = nextR;
                count++;
            }
        }
        return count;
    }
};
