class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0;
        int mod = 1e9+7;
        int parity = 0; long long even = 1, odd = 0;
        for (int i : arr) {
            if (i&1) parity ^= 1;
            if (parity == 1) {
                ans = (ans + even) % mod;
                odd++;
            }
            else {
                ans = (ans + odd) % mod;
                even++;
            }
        }
        return ans;
    }
};