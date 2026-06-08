class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        r = len(matrix)
        c = len(matrix[0])

        row_track = [0]*r
        col_track = [0]*c

        for i in range(r):
            for j in range(c):
                if matrix[i][j] == 0:
                    row_track[i]=-1
                    col_track[j]=-1
        
        #setting rows zero
        for i in range(r):
            row = row_track[i]

            if row<0:
                for j in range(c):
                    matrix[i][j]=0
        #setting column zero
        for j in range(c):
            col = col_track[j]
            if col<0:
                for i in range(r):
                    matrix[i][j] = 0

        