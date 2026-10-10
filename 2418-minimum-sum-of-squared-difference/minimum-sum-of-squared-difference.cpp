class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + (long long)k2, total = 0;
        int maxi = 0;
        vector<int> d(n);
        for (int i=0; i<n; i++) {
            d[i] = abs(nums1[i] - nums2[i]);
            total += d[i];
            maxi = max(maxi, d[i]);
        }
        if (total <= k) return 0;
        int l = 0, r = maxi;
        while (l < r) {
            int mid = l + (r-l) / 2;
            long long need = 0;
            for (int i : d) need += max(0, i - mid);
            if (need <= k) r = mid;
            else l = mid + 1;
        }
        for (int i=0; i<n; i++) {
            k -= max(0, d[i] - l);
            d[i] = min(d[i], l);
        }
        for (int i=0; i<n && k>0; i++) {
            if (d[i]==l) {
                d[i]--;
                k--;
            }
        }
        long long ans = 0;
        for (int i : d) ans += (long long) i * i;
        return ans;
    }
};