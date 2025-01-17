class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int count = 0;
        for(int i = 0; i < derived.size(); i++) count += derived[i];
        return count % 2 == 0;
    }
};