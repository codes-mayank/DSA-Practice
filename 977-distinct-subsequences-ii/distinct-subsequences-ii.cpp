class Solution {
public:
    int distinctSubseqII(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        vector<int> dup(256, -1);
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i=1; i<=n; i++){
            char ch = s[i-1];
            dp[i] = (dp[i-1]*2) % mod;
            if (dup[ch] != -1){
                dp[i] = (dp[i] - dp[dup[ch]-1] + mod) % mod;
            }
            dup[ch] = i;
        }
        for (int i: dp) cout << i << "   ";
        return (dp[n] - 1 + mod)%mod;
    }
};