class Solution:
    def gridGame(self, grid: List[List[int]]) -> int:
        n = len(grid[0])
        sumr1 = sum(grid[0])
        lsum = 0
        for i in range(0, n - 1):
            sumr1 = sumr1 - grid[0][i]
            lsum = lsum + grid[1][i]
            if lsum >= sumr1:
                return max(sumr1, lsum - grid[1][i])
        return lsum

