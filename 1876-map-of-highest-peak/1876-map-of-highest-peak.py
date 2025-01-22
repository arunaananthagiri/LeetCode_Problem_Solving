from collections import deque

class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        n, m = len(isWater), len(isWater[0])
        visited = [[0]*m for _ in range(n)]
        q = deque()
        ht = 1
        dx, dy = [-1,0,1,0], [0,-1,0,1]

        for i in range(n):
            for j in range(m):
                if isWater[i][j] == 1:
                    q.append((i,j))
                    visited[i][j] = 1
                    isWater[i][j] = 0

        while q:
            sz = len(q)
            for k in range(sz):
                i,j = q.popleft()
                for l in range(4):
                    ni, nj = i+dx[l], j+dy[l]
                    if (ni>=0 and ni<n) and (nj>=0 and nj<m) and not visited[ni][nj]:

                        isWater[ni][nj] = ht
                        visited[ni][nj] = 1
                        q.append((ni,nj))
            ht+=1
        return isWater