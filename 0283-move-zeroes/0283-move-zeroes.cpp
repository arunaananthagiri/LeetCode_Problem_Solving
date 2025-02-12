class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int last_index = 0; // last non zero index
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) nums[last_index++] = nums[i];
        }
        for(int i = last_index; i < nums.size(); i++) nums[i] = 0;
    }
};