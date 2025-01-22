class Solution {
public:
    int LPS(int i,int j,string& s,vector<vector<int>>& dp)
    {
        if(i > j) return 0;
        if(i == j) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = 2 + LPS(i + 1, j - 1, s, dp);
        else return dp[i][j] = max(LPS(i + 1, j, s, dp), LPS(i, j - 1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return LPS(0, n - 1, s, dp);
    }
};