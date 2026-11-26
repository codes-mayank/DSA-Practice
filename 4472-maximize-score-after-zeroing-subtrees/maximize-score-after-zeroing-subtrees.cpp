class Solution {
public:
    int dfs(int i, vector<vector<int>>& g, vector<int>& val, vector<int>& op) {
        if (g[i].empty()) return val[i];
        int res = val[i];
        int mn = INT_MAX;
        for (int j: g[i]) {
            int v = dfs(j, g, val, op);
            res += v;
            mn = min(mn, v);
        }
        if (op[i] || mn<0) res -= mn;
        return res;
    }

    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i=1; i<n; i++) g[parent[i]].push_back(i);
        return dfs(0, g, score, op);
    }
};