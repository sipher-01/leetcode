class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        m = len(matrix[0])

        first_col_zero = False
        first_row_zero = False

        # Check if the first column has any zeros
        for i in range(n):
            if matrix[i][0] == 0:
                first_col_zero = True

        # Check if the first row has any zeros
        for j in range(m):
            if matrix[0][j] == 0:
                first_row_zero = True

        # Use first row and column as markers
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        
        # Set matrix cells to zero based on markers in first row/column
        for i in range(1, n):
            if matrix[i][0] == 0:
                for j in range(1, m):
                    matrix[i][j] = 0

        for j in range(1, m):
            if matrix[0][j] == 0:
                for i in range(1, n):
                    matrix[i][j] = 0

        # Zero out the first row if needed
        if first_row_zero:
            for j in range(m):
                matrix[0][j] = 0

        # Zero out the first column if needed
        if first_col_zero:
            for i in range(n):
                matrix[i][0] = 0


        

        
        