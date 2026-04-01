class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // local optimal solution: get how many groups there will be, sort the hands,
        // initialise smallest numbers as beginning of each hand, add a number to each pile in order
        // if they arent the next closest, return false
        unordered_map<int,int> freq;
        for (auto h : hand) {
            freq[h]++;
        }
        sort(hand.begin(), hand.end());
        for (int i = 0; i < hand.size(); i++) {
            if (freq[hand[i]] <= 0) continue;
            for (int j = 0; j < groupSize; j++) {
                int card = hand[i] + j;
                if (freq[card] <= 0) {
                    return false;
                }
                freq[card]--;
            }
        }
        return true;
    }
};
