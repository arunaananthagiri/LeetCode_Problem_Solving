class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mult = nums[i] * nums[j];
                if (m.find(mult) != m.end()) {
                    count += m[mult];
                    m[mult] += 1;
                } 
                else m[mult] = 1;
            }
        }
        return count * 8;
    }
};