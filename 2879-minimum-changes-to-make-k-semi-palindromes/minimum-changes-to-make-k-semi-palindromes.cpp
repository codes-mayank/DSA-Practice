class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = j - i + 1;
                int best = 1e9;
                for (int d = 1; d < l; d++) {
                    if (l % d != 0)
                        continue;
                    int cur = 0;
                    int m = l / d;
                    for (int r = 0; r < d; r++) {
                        for (int t = 0; t < m / 2; t++) {
                            if (s[i + r + t * d] != s[i + r + (m - 1 - t) * d])
                                cur++;
                        }
                    }
                    best = min(best, cur);
                }
                cost[i][j] = best;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int p = 1; p <= k; p++) {
                for (int prev = 0; prev <= i - 2; prev++) {
                    if (dp[prev][p - 1] != 1e9 && cost[prev][i - 1] != 1e9)
                        dp[i][p] =
                            min(dp[i][p], dp[prev][p - 1] + cost[prev][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};