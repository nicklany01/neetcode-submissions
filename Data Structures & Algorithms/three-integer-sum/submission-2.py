class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = []
        nums.sort()
        print(nums)
        for key, val in enumerate(nums):
            if val > 0:
                break
            if key != 0 and val == nums[key - 1]:
                continue
            else:
                twoS = self.twoSum(nums[key + 1:], -val)
                
                if len(twoS) != 0:
                    for x in twoS:
                        ans.append([x[0], x[1], val])
        return ans

    def twoSum(self, nums: List[int], target: int) -> List[List[int]]:
        l, r = 0, len(nums) - 1
        ans = []
        while l < r:
            sum = nums[l] + nums[r]
            if sum < target:
                l += 1
            elif sum > target:
                r -= 1
            else:
                ans.append([nums[l], nums[r]])
                l += 1
                r -= 1
                while nums[l] == nums[l - 1] and l < r:
                    l += 1
        return ans

