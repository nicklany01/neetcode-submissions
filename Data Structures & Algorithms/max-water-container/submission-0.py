class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights) - 1
        biggest = 0
        while l < r:
            area = self.get_area(heights[l], heights[r], r - l)
            biggest = max(biggest, area)
            if heights[l] > heights[r]:
                r -= 1
            else:
                l += 1

        return biggest
    
    def get_area(self, height1, height2, width):
        return width*min(height1, height2)
