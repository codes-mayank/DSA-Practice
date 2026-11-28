class Solution {
public:
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (int i : adj[node]) {
            if (i == parent) continue;
            if (!vis[i]) {
                dfs(i, node, adj, vis, tin, low, bridges);
                if (low[i] > tin[node]) bridges.push_back({node, i});
            }
            else {
                
            }
            low[node] = min(low[node], low[i]);
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& nums) {
        vector<vector<int>> adj(n), bridges;
        for (auto i : nums) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> tin(n), low(n), vis(n);
        dfs(0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};