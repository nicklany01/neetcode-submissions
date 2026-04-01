class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        excess = {}
        for i in range(len(nums)):
            diff = target - nums[i]
            if diff in excess:
                return [excess.get(diff, 0), i]
            excess[nums[i]] = i