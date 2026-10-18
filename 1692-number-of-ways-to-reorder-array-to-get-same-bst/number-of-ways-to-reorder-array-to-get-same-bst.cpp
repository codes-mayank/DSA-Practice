class Solution {
public:
    vector<vector<long long>> C;
    const long long mod = 1e9+7;

    long long ways(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        vector<int> l, r;
        for (int i=1; i<n; i++) {
            if (nums[i] < nums[0]) l.push_back(nums[i]);
            else r.push_back(nums[i]);
        }
        return C[n-1][l.size()] * ways(l) % mod * ways(r) % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        C.assign(n+1, vector<long long>(n+1, 0));
        for (int i=0; i<=n; i++) {
            C[i][0] = 1;
            for (int j=1; j<=i; j++) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
            }
        }
        return (ways(nums) - 1 + mod) % mod;
    }
};