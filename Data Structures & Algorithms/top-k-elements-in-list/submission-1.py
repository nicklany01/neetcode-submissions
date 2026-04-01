class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        hashmap = {}
        for x in nums:
            hashmap[x] = hashmap.get(x, 0) + 1

        arr = []
        for num, cnt in hashmap.items():
            arr.append([cnt,num])
        arr.sort()
            
        result = []
        while len(result) < k:
            result.append(arr.pop()[1])

        return result
            