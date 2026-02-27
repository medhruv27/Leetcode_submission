class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        degrees = [0] * (n + 1)
        
        # 2. Iterate through trust relationships
        # u trusts v -> v's score increases, u's score decreases
        for u, v in edges:
            degrees[v] += 1
            # degrees[u] -= 1
            
        # 3. The judge must have exactly n-1 points 
        # (trusted by everyone else, and trusts no one)
        res = []
        for i in range(0, n):
            if degrees[i] == 0:
                res.append(i)
                
        return res