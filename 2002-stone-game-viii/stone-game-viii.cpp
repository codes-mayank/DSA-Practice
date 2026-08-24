class Solution {
public:
    int findMaximum(int i, vector<int>& prefixSum, vector<int>& dp){
        if (dp[i] != INT_MIN) return dp[i];
        if (i==prefixSum.size()-1) return prefixSum[i];
        int take = prefixSum[i] - findMaximum(i+1, prefixSum, dp);
        int notTake = findMaximum(i+1, prefixSum, dp);
        return dp[i] = max(take, notTake);
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>prefixSum(n);
        prefixSum[0] = stones[0];
        for (int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }
        vector<int>dp(n, INT_MIN);
        // dp[n-1] = prefixSum[n-1];
        // for (int i=n-2; i>=0; i--){
        //     int take = prefixSum[i] - findMaximum(i+1, prefixSum, dp);
        //     int notTake = findMaximum(i+1, prefixSum, dp);
        //     return dp[i] = max(take, notTake);
        // }
        return findMaximum(1, prefixSum, dp);
    }
};