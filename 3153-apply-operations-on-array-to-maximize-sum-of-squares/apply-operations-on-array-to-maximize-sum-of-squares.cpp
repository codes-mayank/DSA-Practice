class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size(), bits[30] = {0};
        long long ans = 0;
        int mod = 1e9+7;
        for (int i=0; i<n; i++) {
            for (int j=0; j<30; j++) {
                if (nums[i] & (1<<j)) bits[j]++;
            }
        }
        while (k--) {
            long x = 0;
            for (int i=0; i<30; i++) {
                if (bits[i] > 0) {
                    x |= 1LL << i;
                    bits[i]--;
                }
            }
            ans = (ans + x*x) % mod;
        }
        return ans;
    }
};