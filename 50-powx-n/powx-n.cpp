class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        long long nn = n;
        bool isNegative = false;
        if (n<0) {
            isNegative = true;
            nn *= -1;
        }
        double ans = 1;
        while (nn>1){
            if (nn&1){
                ans *= x;
            }
            x *= x;
            nn /= 2;
        }
        ans *= x;
        if (isNegative) return 1.0/ans;
        return ans;
    }
};