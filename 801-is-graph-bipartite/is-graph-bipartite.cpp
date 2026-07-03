class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int>vis(V, -1);
        for (int i=0; i<V; i++){
            if (vis[i]!=-1) continue;
            queue<pair<int, int>>q;
            q.push({i, -1});
            vis[i] = 1;
            while (!q.empty()){
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();
                int color = vis[node];
                for (int neighbor : adj[node]){
                    if (neighbor!=parent){
                        if (color == vis[neighbor]) return false;
                        else if (-1==vis[neighbor]){
                            vis[neighbor] = !color;
                            q.push({neighbor, node});
                        }
                    }
                }
            }
        }
        return true;
    }
};