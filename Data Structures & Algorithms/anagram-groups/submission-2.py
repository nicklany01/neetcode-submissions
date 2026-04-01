class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:

        result = defaultdict(list)
        for s in strs:
            dic = {}
            for c in s:
                dic[c] = dic.get(c, 0) + 1
            print(tuple(dic))
            result[tuple(sorted(dic.items()))].append(s)
        return result.values()


        