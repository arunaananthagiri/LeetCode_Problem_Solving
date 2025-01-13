class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> M;
        for(char c : s) M[c]++;
        int del = 0;
        for(auto i : M) {
            if(i.second > 2) {
                if(i.second % 2 == 0) del = del + (i.second - 2);
                else del = del + (i.second - 1);
            }
        }
        return s.length() - del;
    }
};