class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        vector<int> in(V);
        for (auto it : edges) {
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        vector<int>ans, vis(V);
        queue<int> q;
        for (int i=0; i<V; i++ ) {
            if (in[i] == 0) {q.push(i); vis[i] = 1;}
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (int i: adj[node]) {
                if (!vis[i]) {
                    in[i]--;
                    if (in[i] == 0) {
                        q.push(i);
                    vis[i] = 1;
                    }
                    
                }
            }
        }
        return ans.size() == V;
    }
};