class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // k upper bound is max bananas in pile
        // k lower bound is h
        int maxB = 0;
        for (int p : piles) {
            maxB = max(maxB, p);
        }
        int l = 1;
        int r = maxB;
        int k;
        int result = r;
        while (l <= r) {
            // better than (l + r) / 2 because it doesnt cause integer overflow
            k = l + (r - l) / 2;
            cout << k << "\n";
            // check if its a valid solution, if it is try to optimise it
            if (validSolution(piles, h, k)) {
                result = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return result;
    }

private:
    bool validSolution(vector<int>& piles, int h, int k) {
        int s = 0;
        for (int p : piles) {
            s += (p + k - 1)/ k;
        }
        return s <= h;
    }
};
