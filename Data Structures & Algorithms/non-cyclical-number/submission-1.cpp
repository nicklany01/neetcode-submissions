class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int sum = -1;
        do {
            s.insert(sum);
            // calculate next sum of squares of digits
            sum = 0;
            while (n > 0) {
                cout << n << endl;
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            cout << sum << endl;
            // update next number
            if (sum == 1) {
                return true;
            }
            n = sum;
        } while (!s.contains(sum));
        return false;
    }
};
