class Solution {
public:
    int countPaths(int n, vector<vector<int>>& times) {
        int mod = 1e9+7;
        vector<vector<pair<long long, long long>>> adj(n+1);
        for (auto it: times) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n);
        ways[0] = 1;
        dist[0] = 0;
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dist[node]) continue;
            for (auto it: adj[node]){
                int u = node, v = it.first, w = it.second;
                if (d + w < dist[v]) {
                    dist[v] = d + w;
                    ways[v] = ways[u];
                    pq.push({dist[it.first], it.first});
                }
                else if (d + w == dist[v]){
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }
        return ways[n-1];
    }
};