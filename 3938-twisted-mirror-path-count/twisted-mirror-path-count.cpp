class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp, int dir) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j >= n)
            return 0;
        if (i == m-1 && j == n-1) return 1;
        if (dp[i][j][dir] != -1) return dp[i][j][dir];
        if (grid[i][j] == 0) {
            return dp[i][j][dir] = ((helper(i+1, j, grid, dp, 1)%mod) + (helper(i, j+1, grid, dp, 0)%mod))% mod;
        }
        else {
            if (dir == 1) {
                dp[i][j][dir] = helper(i, j+1, grid, dp, 0);
            }
            else dp[i][j][dir] = helper(i+1, j, grid, dp, 1);
        }
        return dp[i][j][dir];
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return helper(0, 0, grid, dp, 0);
    }
};