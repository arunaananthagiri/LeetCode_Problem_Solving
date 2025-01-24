class Solution {
public:
    long long mod=1000000007;
    int helper(string &s,int index,int k,vector<int>&dp){
        if(index >= s.size()) return 1;
        if(s[index] == '0') return 0;

        if(dp[index] != -1) return dp[index];

        int ans = 0;
        long long num = 0;
        for(int j = index; j < s.size(); j++){
            num = num * 10 + (s[j] - '0');
            if(num > k) break;
            ans = (ans % mod + helper(s, j + 1, k, dp)) % mod;
            
        }
        return dp[index] = ans;
    }
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size() + 1, -1);
        return helper(s, 0, k, dp);
    }
};