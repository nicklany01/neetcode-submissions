class Solution:
    def isPalindrome(self, s: str) -> bool:
        fs = ''.join(filter(lambda char: 'a' <= char <= 'z' or 'A' <= char <= 'Z' or '0' <= char <= '9', s)).lower()
        start, end = 0, len(fs) - 1
        if len(s) < 2:
            return True
        while start < end:
            if fs[start] != fs[end]:
                return False
            start += 1
            end -= 1
        return True