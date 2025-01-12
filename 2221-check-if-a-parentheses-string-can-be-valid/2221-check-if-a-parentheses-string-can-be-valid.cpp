class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length() % 2 == 1) return false;
        int x = 0, y = 0;
        for(int i = 0; i < s.length(); i++) {
            if(locked[i] == '1') {
                if(s[i] == '(') {
                    x++;
                    y++;
                }
                else {
                    x = max(0, x - 1);
                    y--;
                }
            }
            else {
                x = max(0, x - 1);
                y++;
            }
            if(y < 0) return false;
        }
        return x == 0;
    }
};