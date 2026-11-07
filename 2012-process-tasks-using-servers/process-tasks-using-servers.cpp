struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> s;
        for (int i=0; i<servers.size(); i++) {
            s.push({servers[i], i});
        }
        priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> suspended;
        long long time = 0;
        int i = 0;
        vector<int> ans;
        while (i < tasks.size()) {
            time = max(time, (long long)i);
            if (s.empty()) {
                time = max(time, suspended.top().first); 
            }
            while (!suspended.empty() && suspended.top().first <= time) {
                auto [x, idx] = suspended.top();
                suspended.pop();
                s.push({servers[idx], idx});
            }
            auto [w, idx] = s.top();
            s.pop();
            ans.push_back(idx);
            suspended.push({time + tasks[i], idx});
            i++;
        }
        return ans;
    }
};