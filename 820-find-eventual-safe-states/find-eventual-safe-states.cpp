class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pre, vector<bool>& isSafe){
        vis[node] = 1;
        pre[node] = 1;
        for (auto it : adj[node]){
            if (vis[it] && pre[it]){
                return true;
            }
            else if (!vis[it]){
                if (dfs(it, adj, vis, pre, isSafe)) return true;
            }
        }
        pre[node] = 0;
        isSafe[node] = true;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<bool> pre(V, false), vis(V, false), isSafe(V, false);
        for (int i=0; i<V; i++){
            if (!vis[i]){
                dfs(i, graph, vis, pre, isSafe);
            }
        }
        vector<int> res;
        for (int i=0; i<V; i++) if (isSafe[i]) res.push_back(i);
        return res;
    }
};