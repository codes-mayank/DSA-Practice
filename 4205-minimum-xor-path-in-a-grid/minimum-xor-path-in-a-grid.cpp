class Solution {
public:
    int helper(int i, int j, int x, vector<vector<int>>& grid, vector<vector<vector<int>>>& xorr) {
        if (i<0 || j<0) return 0;
        if (i==0 && j==0) return x == grid[0][0];
        if (xorr[i][j][x] != -1) return xorr[i][j][x];
        // for (int k=0; k<1024; k++) {
        //     if (i>0 &&  helper(i-1, j, k, grid, xorr)==1) xorr[i][j][k^grid[i][j]] = 1;
        //     if (j>0 &&  helper(i, j-1, k, grid, xorr)==1) xorr[i][j][k^grid[i][j]] = 1;
        // }
        // xorr[i+1][j][x] = helper(i+1, j, x,  grid, xorr);
        // xorr[i][j+1][x] = helper(i, j+1, x, grid, xorr);
        int prev = x ^ grid[i][j];
        return xorr[i][j][x] = helper(i-1, j, prev, grid, xorr) || helper(i, j-1, prev, grid, xorr);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> xorr(m+1, vector<vector<int>>(n+1, vector<int>(1024, -1)));
        xorr[0][0][grid[0][0]] = 1;
        for (int i=0; i<1024; i++) if (helper(m-1, n-1, i, grid, xorr)) return i;
        return -1;
    }
};