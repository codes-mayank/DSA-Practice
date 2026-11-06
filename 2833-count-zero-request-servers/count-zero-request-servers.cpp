class Solution {
public:
    bool static comp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int, int>> sortedq;
        sort(logs.begin(), logs.end(), comp);
        for (int i=0; i<queries.size(); i++) sortedq.push_back({queries[i], i});
        sort(sortedq.begin(), sortedq.end());
        vector<int> ans(queries.size());
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        // for (auto it: logs) cout << it[0] << "--" << it[1] <<endl;
        // while (j<queries.size()) {
            for (auto [time, idx] : sortedq) {
                while (j<logs.size() && logs[j][1] <= time) {
                    mp[logs[j][0]]++;
                    j++;
                }
                cout << mp.size() << endl;
                while (i<j && (time - x) > logs[i][1]) {
                    mp[logs[i][0]]--;
                    if (mp[logs[i][0]] == 0) mp.erase(logs[i][0]);
                    i++;
                }
                ans[idx] = (n - mp.size());
            // }

        }
        return ans;
    }
};