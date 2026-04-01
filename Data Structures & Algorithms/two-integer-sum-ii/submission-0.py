class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for x in range(len(numbers)):
            for y in range(len(numbers)):
                if target - numbers[y] == numbers[x]:
                    return [x + 1, y + 1]