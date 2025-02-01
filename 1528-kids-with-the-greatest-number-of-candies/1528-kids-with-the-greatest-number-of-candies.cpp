class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maximum = -1;
        for(int i = 0; i < candies.size(); i++) 
            maximum = max(candies[i], maximum);
        vector<bool> res(candies.size(), false);
        for(int i = 0; i < candies.size(); i++) {
            int p = candies[i] + extraCandies;
            if(p >= maximum) res[i] = true;
            else res[i] = false;
        }
        return res;
    }
};