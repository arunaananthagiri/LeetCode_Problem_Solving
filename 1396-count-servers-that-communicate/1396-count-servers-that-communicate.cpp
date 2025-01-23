class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row_count(n, 0);
        vector<int> col_count(m, 0);
        int tot = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    tot++;
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] && row_count[i] == 1 && col_count[j] == 1) tot--;
            }
        }
        return tot;
    }
};