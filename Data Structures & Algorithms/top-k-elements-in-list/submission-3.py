class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Bucket sort (hopefully)
        hashmap = {}
        for x in nums:
            hashmap[x] = hashmap.get(x, 0) + 1

        # make buckets
        freq = []
        for x in nums:
            freq.append([])

        # put in buckets
        for num, cnt in hashmap.items():
            freq[cnt - 1].append(num)
        
        result = []
        for i in range(len(freq) - 1, -1, -1):
            for num in freq[i]:
                result.append(num)
                if len(result) >= k:
                    print(result)
                    return result