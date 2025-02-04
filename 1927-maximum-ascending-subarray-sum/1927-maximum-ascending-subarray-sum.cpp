class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], current = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            current = nums[i] > nums[i - 1] ? current + nums[i] : nums[i];
            ans = max(ans, current);
        }
        return ans;
    }
};