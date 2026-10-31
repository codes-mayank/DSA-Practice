class Solution {
public:
    unsigned long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n / 2) r = n - r;
        
        unsigned long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - i + 1) / i;
        }
        return res;
    }   

    int waysToReachStair(int k) {
        long long ans = 0;
        for (int i=0; i<=31; i++) {
            int down = (1LL<<i) - k;
            if (down >= 0 && down <= i+1) {
                ans += nCr(i+1, down);
            }
        }
        return ans;
    }
};