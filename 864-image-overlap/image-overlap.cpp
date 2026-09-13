class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> A, B;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                if (img1[i][j]) A.push_back({i, j});
                if (img2[i][j]) B.push_back({i, j});
            }
        }
        vector<vector<int>> cnt(n*2, vector<int>(n*2));
        int res = 0;
        for (auto& i: A){
            for (auto& j: B){
                int dx = i.first - j.first;
                int dy = i.second - j.second;
                res = max(res, ++cnt[dx+n][dy+n]);
            }
        }
        return res;
    }
};