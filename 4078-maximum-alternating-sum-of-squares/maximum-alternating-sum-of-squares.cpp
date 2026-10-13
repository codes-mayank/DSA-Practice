class Solution {
public:
    bool static comp(const int a, const int b) {
        long long x = a, y = b;
            if (x<0) x = -x;
            if (y<0) y = -y;
            return x >= y;
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squares;
        for (int i: nums) squares.push_back(1LL*i*i);
        sort(squares.begin(), squares.end());

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (i < (n + 1) / 2)
                ans += squares[n - 1 - i];
            else
                ans -= squares[n - 1 - i];
        }
        return ans;
    }
};