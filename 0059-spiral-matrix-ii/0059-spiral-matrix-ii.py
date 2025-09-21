class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        top,bottom ,left ,right = 0,n-1,0,n-1
        c,t = 1,n*n
        res = [[0] * n for _ in range(n)]        
        while(c<=t):
            for i in range(left,right+1):
                if c > t:
                  break
                res[top][i] = c
                c+=1
            
            top+=1
            for i in range(top,bottom+1):
                if c > t:
                  break
                res[i][right] = c;
                c+=1
            
            right-=1
            for i in range(right,left-1,-1):
                if c > t:
                  break
                res[bottom][i] = c;
                c+=1
            
            bottom-=1
            for i in range(bottom,top-1,-1):
                if c > t:
                  break
                res[i][left] = c
                c+=1
            
            left+=1
        
        return res
        