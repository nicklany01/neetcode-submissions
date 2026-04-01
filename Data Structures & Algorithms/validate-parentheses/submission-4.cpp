class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for (char c : s) {
            if (c == '[' || c == '(' || c == '{') {
                par.push(c);
            }
            if (c == ']' || c == ')' || c == '}') {
                if (par.empty() || !isMatching(par.top(), c)) return false;
                par.pop();
            }
        }
        if (!par.empty()) return false;
        return true;
    }

    bool isMatching(char opener, char closer) {
        if (opener == '(' && closer == ')') return true;
        if (opener == '[' && closer == ']') return true;
        if (opener == '{' && closer == '}') return true;
        return false;
    }
};
