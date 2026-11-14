class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        long long ans = INT_MAX;
        for (int i=0; i<n; i++) {
            long long sum = 0;
            for (int j=i; j<n; j++) {
                sum += nums[j];
                if (sum > 0 && ((j-i+1) <= r && (j-i+1) >= l)) ans = min(ans, sum);
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};