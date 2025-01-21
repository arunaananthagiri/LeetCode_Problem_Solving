class Solution {
public:
    int solve(int n) {
        if(n == 0 || n == 1) return n;
        if(n == 2) return 1;
        int prev1 = 0, prev2 = 1, prev3 = 1, current = 0;
        for(int i = 3; i <= n; i++) {
            current = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = current;
        }
        return current;
    }
    int tribonacci(int n) {
        return solve(n);
    }
};