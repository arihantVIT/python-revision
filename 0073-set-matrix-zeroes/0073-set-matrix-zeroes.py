class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r = len(matrix)
        c = len(matrix[0])

        indices = []

        for i in range(r):
            for j in range(c):
                if matrix[i][j]==0:
                    indices.append([i,j])
        
        for idx in indices:

            #converting rows
            for j in range(c):
                i = idx[0]
                matrix[i][j] = 0
            
            for i in range(r):
                j = idx[1]
                matrix[i][j] = 0