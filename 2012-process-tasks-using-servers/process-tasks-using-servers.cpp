class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();

        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            greater<>> available;

        priority_queue<pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>> busy;

        for (int i = 0; i < n; i++) {
            available.emplace(servers[i], i);
        }

        vector<int> ans(m);
        long long time = 0;

        for (int i = 0; i < m; i++) {
            time = max(time, (long long)i);

            if (available.empty()) {
                time = max(time, busy.top().first);
            }

            while (!busy.empty() && busy.top().first <= time) {
                int idx = busy.top().second;
                busy.pop();
                available.emplace(servers[idx], idx);
            }

            int idx = available.top().second;
            available.pop();

            ans[i] = idx;
            busy.emplace(time + tasks[i], idx);
        }

        return ans;
    }
};