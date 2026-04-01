class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dupDict = dict()
        for num in nums:
            if num in dupDict:
                return True
            dupDict[num] = 1
        return False