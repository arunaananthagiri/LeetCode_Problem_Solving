class Solution {
public:
    vector<string> m;
    void solve(int i, int j, int n, string s) {
        if(i == j && i == n) {
            m.push_back(s);
            return;
        }
        if(i < n) solve(i + 1, j, n, s + '(');
        if(j < i) solve(i, j + 1, n, s + ')');
    }
    vector<string> generateParenthesis(int n) {
        m.clear();
        solve(0, 0, n, "");
        return m;
    }
};