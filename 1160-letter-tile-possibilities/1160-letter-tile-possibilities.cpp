class Solution {
public:
    unordered_set<string>v;
    void f(string &t,int i,string &s){
        v.insert(s);
        for(int j = i;j<t.size();j++){
            if(j!=i && t[j]==t[j-1]) continue;
            s.push_back(t[j]);
            f(t,j+1,s);
            s.pop_back();
        }
    }

    int fac(int n){
        int ans = 1;
        for(int i = 1;i<=n;i++) ans *=i;
        return ans;
    }

    int numTilePossibilities(string t) {
        sort(t.begin(),t.end());
        int ans = 0;
        string s = "";
        f(t,0,s);
        for(auto s : v){
            if(s.size()==0) continue;
            map<char,int>m;
            for(char c : s) m[c]++;
            int n = s.size();
            int nfac = fac(n);
            int deno = 1;
            for(auto e : m){
                int fr = e.second;
                int frfac = fac(fr);
                deno *= frfac;
            }
            ans += nfac/deno;
        }
        return ans;
    }
};