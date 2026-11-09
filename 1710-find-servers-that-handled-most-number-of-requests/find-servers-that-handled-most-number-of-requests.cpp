class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> free;
        vector<int> cnt(k);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        for (int i=0; i<k; i++) free.insert(i);
        for (int i=0; i<n; i++) {
            int t = arrival[i];
            while (!busy.empty() && busy.top().first <= t) {
                free.insert(busy.top().second);
                busy.pop();
            }
            if (free.empty()) continue;
            int pref = i % k;
            auto it = free.lower_bound(pref);
            if (it == free.end()) it = free.begin();
            int s = *it;
            cnt[s]++;
            free.erase(it);
            busy.emplace(t+load[i], s);
        }
        int maxi = *max_element(cnt.begin(), cnt.end());
        vector<int> ans;
        for (int i=0; i<k; i++ ) {
            if (cnt[i] == maxi) ans.push_back(i);
        }
        return ans;
    }
};