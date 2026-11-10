class Solution {
public:
    int helper(int i,  vector<int>& costs, vector<int>& dp) {
        int n = costs.size();
        if (i == n-1) return 0;
        if (dp[i+1] != -1) return dp[i+1];
        int s1 = (i<n-1) ? costs[i+1] + 1 + helper(i+1, costs, dp) : INT_MAX;
        int s2 = (i<n-2) ? costs[i+2] + 4 + helper(i+2, costs, dp) : INT_MAX;
        int s3 = (i<n-3) ? costs[i+3] + 9 + helper(i+3, costs, dp) : INT_MAX;
        return dp[i+1] = min(s1, min(s2, s3));
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, -1);
        return helper(-1, costs, dp);
    }
};