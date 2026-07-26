class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pre, vector<int>& nums){
        vis[node] = 1;
        pre[node] = 1;
        for (auto it : adj[node]){
            if (vis[it] && pre[it]){
                return true;
            }
            else if (!vis[it]){
                if(dfs(it, adj, vis, pre, nums)){
                    return true;
                }
            }
        }
        nums[node] = 1;
        pre[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n), path(n), nums(n);
        for (int i=0; i<n; i++){
            if (!vis[i]) dfs(i, graph, vis, path, nums);
        }
        vector<int>safeNodes;
        for (int i=0; i<n; i++) if (nums[i]) safeNodes.push_back(i);
        return safeNodes;
    }
};