class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # have a list of dicts for each string, these can later be compared and grouped
        # dicts = [{} for _ in range(len(strs))]
        # for x in range(len(strs)):
        #     for y in strs[x]:
        #         dicts[x][y] = dicts[x].get(y, 0) + 1
        # dict2 = {}
        # for x in range(len(strs)):
        #     dict2[dicts[x]] = dicts.get()
        
        result = defaultdict(list)
        for s in strs:
            dic = {}
            for c in s:
                dic[c] = dic.get(c, 0) + 1
            print(tuple(dic))
            result[tuple(sorted(dic.items()))].append(s)
        return result.values()


        