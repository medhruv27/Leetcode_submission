class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        mp = {} 
        for it in roads:
            mp[(it[0], it[1])] = 1
        indeg = [0] * n
        for i in range(0,n):
            for it in roads:
                f = it[0]
                s = it[1]
                if i==f or i==s:
                    indeg[i]+=1
                
        res=-1 
        for i in range(0,n-1):
            for j in range(i+1,n):
                if (i,j) in mp or (j,i) in mp:
                    res = max(res,indeg[i]+indeg[j]-1)
                else:
                    res = max(res,indeg[i]+indeg[j])
        return res