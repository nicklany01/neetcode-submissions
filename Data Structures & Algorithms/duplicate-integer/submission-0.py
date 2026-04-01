class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dic = {}
        for x in nums:
            if x in dic:
                return True
            dic[x] = True
        return False