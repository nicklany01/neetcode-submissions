class Solution:
    def isPalindrome(self, s: str) -> bool:
        l, r = 0, len(s) - 1
        while r > l:
            if not s[l].isalnum():
                l += 1
                continue
            if not s[r].isalnum():
                r -= 1
                continue
            if s[l].lower() != s[r].lower():
                print(s[r])
                print(s[l])
                return False
            r -= 1
            l += 1
        return True

