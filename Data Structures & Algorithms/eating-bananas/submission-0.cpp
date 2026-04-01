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
        while (l <= r) {
            k = l + (r - l) / 2;
            cout << k << "\n";
            // check if its a valid solution, if it is try to optimise it
            if (validSolution(piles, h, k)) {
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        if (validSolution(piles, h, k)) {
            return k;
        } else {
            return k + 1;
        }
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
