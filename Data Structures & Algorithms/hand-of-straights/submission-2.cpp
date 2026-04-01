class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // local optimal solution: get how many groups there will be, sort the hands,
        // initialise smallest numbers as beginning of each hand, add a number to each pile in order
        // if they arent the next closest, return false
        int n = hand.size()/groupSize;
        if (n * groupSize != hand.size()) return false;
        sort(hand.begin(), hand.end());
        for (int i = 0; i < n; i++) {
            // find the first non removed num
            int j = 0;
            int prev = -1;
            while (prev == -1 && j < hand.size()) {
                prev = hand[j++];
            }
            hand[j-1] = -1;
            cout << "prev: " << prev << endl;
            if (prev == -1) return false;
            j = 0;
            int count = 1;
            while (j < hand.size() && count < groupSize) {
                // has been removed
                cout << hand[j] << endl;
                if (hand[j] != -1 && prev + 1 == hand[j]) {
                    count++;
                    prev = hand[j];
                    // remove from list
                    hand[j] = -1;
                } 
                j++;
            }
            if (count != groupSize) return false;
        }
        return true;
    }
};
