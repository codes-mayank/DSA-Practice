class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        long long ans = 0;
        for (int j=0; j<intervals.size(); j++) {
            int end = intervals[j][1];
            int x = upper_bound(intervals.begin()+j+1, intervals.end(), end, [](int val, const vector<int>& seg){
                return val < seg[0];
            })-intervals.begin();
            ans += x - j - 1;
        }
        return ans;
    }
};