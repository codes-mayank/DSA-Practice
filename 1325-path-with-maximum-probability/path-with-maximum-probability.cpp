class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& times, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n+1);
        for (int i=0; i<times.size(); i++){ 
            adj[times[i][0]].push_back({times[i][1], succProb[i]});
            adj[times[i][1]].push_back({times[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        pq.push({1, start_node});
        vector<double> dist(n+1, 0);
        dist[start_node] = 1;
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            for (auto it: adj[node]){
                if (d * it.second > dist[it.first]) {
                    dist[it.first] = d * it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        return dist[end_node] != INT_MIN ? dist[end_node] : 0;
    }
};