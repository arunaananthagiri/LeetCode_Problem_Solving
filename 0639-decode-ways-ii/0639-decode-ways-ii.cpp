const int mod = 1e9+7 ;
class Solution {
public:
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,-1);

        dp[s.length()]=1 ;
        return solve(s,0,dp)%mod;
    }
    
    int solve(string& s,int p,vector<int>&dp){
        
        if(p==s.length())return dp[p]%mod;
        
        if(dp[p]>-1){
            return dp[p]%mod;
        }
        
        if(s[p]=='0')return dp[p]=0 ;
        
        
        int res ;
        if(s[p]!='*')
            res = solve(s,p+1,dp)%mod;
        else 
            res= (  9L *(solve(s,p+1,dp))%mod)%mod ;
            
        if(p<s.length()-1){
            if(s[p]=='1'){
                if(s[p+1]=='*'){
                    res =(res%mod + (9L * solve(s,p+2,dp)%mod)%mod)%mod;
                }else{
                    res = (res%mod + solve(s,p+2,dp)%mod)%mod;
                }
            }
            else if(s[p]=='2'){
                if(s[p+1]=='*'){
                    res = (res%mod + (6L*solve(s,p+2,dp)%mod)%mod)%mod;
                }else if(s[p+1]>='0' and s[p+1]<='6'){
                    res = (res%mod +solve(s,p+2,dp)%mod)%mod;
                }
            }else if(s[p]=='*'){
                if(s[p+1]=='*'){
                    res=(res%mod+ (15L *solve(s,p+2,dp)%mod)%mod)%mod;               
                }else if(s[p+1]>='0' and s[p+1]<='6'){
                    res=(res%mod+ (2L *solve(s,p+2,dp)%mod)%mod)%mod;
                }else{
                    res = (res%mod + solve(s,p+2,dp)%mod)%mod;
                }
            }
        }
        
        return dp[p]=res%mod ;
        
    }
};