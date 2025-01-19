class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][m - 1], i, m - 1});  
            vis[i][0] = true;
            vis[i][m - 1] = true;
        }

        for(int i = 0; i < m; ++i) {
            pq.push({heightMap[0][i], 0, i});
            pq.push({heightMap[n - 1][i], n - 1, i});
            vis[0][i] = true;
            vis[n - 1][i] = true;
        }

        int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ans = 0, max_height = 0;
        
        while(!pq.empty()) {
            auto[height, r, c] = pq.top();
            pq.pop();
            max_height = max(max_height, height);
            ans += max_height - height;
            for(int i = 0; i < 4; ++i) {
                int row = dirs[i][0] + r, col = dirs[i][1] + c;
                if(row < 0 || row >= n || col < 0 || col >= m || vis[row][col]) continue;
                vis[row][col] = true;
                pq.push({heightMap[row][col], row, col});
            }
        }
        return ans;
    }
};