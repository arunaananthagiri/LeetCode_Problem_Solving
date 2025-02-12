class Solution {
public:
    int sumofdigits(int num){
        int sum = 0;
        while(num != 0) {
            sum = sum + (num % 10);
            num = num / 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> m;
        int maximum = -1;
        for(int i : nums) {
            int s = sumofdigits(i);
            if(m.find(s) != m.end()) {
                maximum = max(maximum, m[s] + i);
                m[s] = max(m[s], i);
            }
            else m[s] = i;
        }
        return maximum;
    }
};