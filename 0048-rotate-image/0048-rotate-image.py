class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r = len(matrix)
        n = len(matrix[0])
        c = int(n/2)
        for i in range(0,r):
            for j in range(0,i+1):
                matrix[i][j] , matrix[j][i] = matrix[j][i] , matrix[i][j]
        
        for i in range(0,r):
            for j in range(0,c):
                matrix[i][j] , matrix[i][n-j-1] = matrix[i][n-j-1] , matrix[i][j]
