class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
        > q;
        int res = INT_MAX;
        vector<int> nc = {0, 1, 0, -1};
        vector<int> nr = {-1, 0, 1, 0};
        vector<vector<int>> dist(m ,vector<int> (n, INT_MAX));
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        while (!q.empty()) {
            int effort = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            for (int i=0; i<4; i++) {
                int row = r + nr[i];
                int col = c + nc[i];
                if (row >=0 && row<m && col >=0 && col<n) {
                    int nd = abs(heights[r][c] - heights[row][col]);
                    int neffort = max(effort, nd);
                    if (neffort < dist[row][col]) {
                        q.push({neffort, {row, col}});
                        dist[row][col] = neffort;
                    }

                }
            }
        }
        return dist[m-1][n-1];
    }
};