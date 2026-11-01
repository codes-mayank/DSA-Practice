class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i: nums) mini = min(mini, i);
        long long ans = 0;
        for (int i: nums) ans += i - mini;
        return ans;
    }
};