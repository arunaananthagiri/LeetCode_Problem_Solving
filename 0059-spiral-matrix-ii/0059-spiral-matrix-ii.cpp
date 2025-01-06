class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> m(n, vector<int>(n, 0));
        int count = 1;
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        while(left <= right && top <= bottom) {
            for(int i = left; i <= right; i++) {
                m[top][i] = count; 
                count++;
            }
            top++;
            for(int i = top; i <= bottom; i++) {
                m[i][right] = count;
                count++;
            }
            right--;
            for(int i = right; i >= left; i--) {
                m[bottom][i] = count;
                count++;
            }
            bottom--;
            for(int i = bottom; i >= top; i--) {
                m[i][left] = count;
                count++;
            }
            left++;
        }
        return m;
    }
};