class Solution {
public:
    long long mod1 = 1000000007LL, mod2 = 1000000009LL;
    long long base1 = 1000003LL, base2 = 1000033LL;

    bool isValid(vector<int>& nums, vector<long long>& h1, vector<long long>& h2, vector<long long>& p1, vector<long long>&p2, int len) {
        int n = nums.size();

        map<pair<int, int>, int> cnt;

        for (int i = 0; i + len <= n; i++) {
            long long a = (h1[i + len] - h1[i] * p1[len] % mod1 + mod1) % mod1;
            long long b = (h2[i + len] - h2[i] * p2[len] % mod2 + mod2) % mod2;
            cnt[{a, b}]++;
        }
        for (auto it : cnt)
            if (it.second == 1)
                return true;
        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> h1(n + 1), h2(n + 1), p1(n + 1), p2(n + 1);
        p1[0] = p2[0] = 1;
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * base1 + nums[i]) % mod1;
            h2[i + 1] = (h2[i] * base2 + nums[i]) % mod2;
            p1[i + 1] = p1[i] * base1 % mod1;
            p2[i + 1] = p2[i] * base2 % mod2;
        }
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (isValid(nums, h1, h2, p1, p2, mid)) {
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return l;
    }
};