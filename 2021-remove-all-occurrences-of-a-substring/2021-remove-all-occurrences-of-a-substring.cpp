class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = part.length();
        string ans;
        for(char i : s) {
            ans.push_back(i);
            while(ans.find(part) < ans.length()) {
                for(int j = 0; j < len; j++) ans.pop_back();
            }
        }
        return ans;
    }
};