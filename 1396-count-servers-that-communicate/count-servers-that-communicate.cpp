class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int>row(m), col(n);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans = 0;
        vector<vector<int>> vis(m, vector<int>(n));
        for (int i=0; i<m; i++) {
            if (row[i] > 1) {
                for (int j=0; j<n; j++) {
                    if (!vis[i][j] && grid[i][j]) {
                        vis[i][j] = 1;
                        ans++;
                    }
                }
            } 
        }
        for (int j=0; j<n; j++) {
            if (col[j] > 1) {
                for (int i=0; i<m; i++) {
                    if (!vis[i][j] && grid[i][j]) {
                        vis[i][j] = 1;
                        ans++;
                    }
                }
            } 
        }
        return ans;
    }
};