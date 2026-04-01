class Solution {
public:
    bool isPalindrome(string s) {
        //iterator backwards and forwards, until they are each other, or one goes past the other
        auto it_f = s.begin();
        auto it_b = s.end();
        
        while (it_f < it_b) {
            if (!isalnum(*it_f)) {
                it_f++;
                continue;
            }
            if (!isalnum(*it_b)) {
                it_b--;
                continue;
            }
            if (tolower(*it_f) != tolower(*it_b)) {
                std::cout << *it_b;
                std::cout << *it_f;
                return false;
            }
            it_f++;
            it_b--;
        }
        return true;
    }
};

