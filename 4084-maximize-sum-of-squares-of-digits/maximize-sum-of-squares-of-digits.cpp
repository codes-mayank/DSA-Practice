class Solution {
public:
    string maxSumOfSquares(int num, int Sum) {
        string ans = "";
        int sum = Sum;
        long long s = 0;
        for (int i=0; i<num; i++) {
            int j;
            for (j=9; j>=0; j--) {
                if (j <= sum) {
                    break;
                }
            }
            sum -= j;
            s += j;
            char ch = '0' + j;
            ans += ch;
        }
        if (s == Sum) return ans;
        return "";
    }
};