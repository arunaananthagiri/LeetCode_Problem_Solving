class Solution {
public: 
    bool isSafe(int row, int col, vector<string>& temp, int n){
        int duprow = row;
        int dupcol = col;
        while (row >= 0 && col >= 0) {
            if (temp[row][col] == 'Q') return false;
            row--; 
            col--;
        }
        row = duprow;
        col = dupcol;
        
        while (col >= 0) {
            if (temp[row][col] == 'Q') return false;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        
        while (row < n && col >= 0) {
            if (temp[row][col] == 'Q') return false;
            row++; 
            col--;
        }
        
        return true; 
    }

    void solve(int col, vector<vector<string>>& ans, vector<string>& temp, int n) {
        if (col == n) {
            ans.push_back(temp);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, temp, n)) { 
                temp[row][col] = 'Q'; 
                solve(col + 1, ans, temp, n); 
                temp[row][col] = '.'; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> temp(n, string(n, '.')); 
        solve(0, ans, temp, n); 
        return ans; 
    }
};