class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char value) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == value) return false;
            if (board[i][col] == value) return false;
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == value) return false;
        }
        return true;
    }
    bool canSolve(vector<vector<char>>& board){
         for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') {
                    for(char value = '1'; value <= '9'; value++) {
                        if(isValid(board, row, col, value)) {
                            board[row][col] = value;
                            if(!canSolve(board)) board[row][col] = '.';
                            else return true; 
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
       canSolve(board);
    }
};