class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        diffMap = {}
        for key, value in enumerate(nums):
            diff = target - value
            if diff in diffMap:
                return [diffMap[diff], key]
            diffMap[value] = key
