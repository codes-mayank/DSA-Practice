class Solution {
public:

    int shortestPath(int V, vector<vector<int>>& edges, string s, int k) {
        vector<vector<pair<int, int>>> adj(V);
        for (auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<vector<int>> dist(V, vector<int>(k + 1, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();
            if (u == V - 1)
                return d;
            if (d > dist[u][cnt])
                continue;

            for (auto [v, wt] : adj[u]) {
                int ncnt = (s[u] == s[v] ? cnt + 1 : 1);
                if (ncnt > k)
                    continue;
                if (d + wt < dist[v][ncnt]) {
                    dist[v][ncnt] = d + wt;
                    pq.push({d + wt, v, ncnt});
                }
            }
        }

        return -1;
    }
};