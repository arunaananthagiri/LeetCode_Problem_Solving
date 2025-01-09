class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for (auto i : words) {
            if (i.length() < pref.length()) continue;
            string curr_pref = "";
            for (int j = 0; j < pref.length(); j++) curr_pref += i[j];
            if (curr_pref == pref) count++;
        }
        return count;
    }
};