class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis){
        vis[i][j] = 1;
        int nrow[] = {-1, 0, 1, 0};
        int ncol[] = {0, 1, 0, -1};
        int m = grid.size(), n = grid[0].size();
        for (int it=0; it<4; it++){
            int newrow = i + nrow[it];
            int newcol = j + ncol[it];
            if (0<=newrow && m>newrow && 0<=newcol && n>newcol && grid[newrow][newcol]==0 && !vis[newrow][newcol]){
                dfs(grid, newrow, newcol, vis);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m, vector<int> (n, 0));
        for (int i=0; i<m; i++) {
            if (!vis[i][0] && grid[i][0]==0) dfs(grid, i, 0, vis);
        }
        for (int i=0; i<m; i++) {
            if (!vis[i][n-1] && grid[i][n-1]==0) dfs(grid, i, n-1, vis);
        }
        for (int i=0; i<n; i++) {
            if (!vis[0][i] && grid[0][i]==0) dfs(grid, 0, i, vis);
        }
        for (int i=0; i<n; i++) {
            if (!vis[m-1][i] && grid[m-1][i]==0) dfs(grid, m-1, i, vis);
        }
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (!vis[i][j] && grid[i][j]==0) {dfs(grid, i, j, vis); ans++;}
            }
        }
        return ans;
    }
};