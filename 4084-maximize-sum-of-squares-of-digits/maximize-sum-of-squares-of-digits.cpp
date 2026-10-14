class Solution {
public:
    string maxSumOfSquares(int num, int Sum) {
        string ans = "";
        int sum = Sum;
        long long s = 0;
        for (int i=0; i<num; i++) {
            int j = sum > 9 ? 9 : sum;
            sum -= j;
            s += j;
            char ch = '0' + j;
            ans += ch;
        }
        if (s == Sum) return ans;
        return "";
    }
};