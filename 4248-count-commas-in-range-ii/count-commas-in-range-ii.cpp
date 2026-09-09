class Solution {
public:
    long long countCommas(long long n) {
        long long res = 0;
        res += n > 999 ? n - 999 : 0;
        res += n > 999999 ? n - 999999 : 0;
        res += n > 999999999 ? n - 999999999 : 0;
        res += n > 999999999999 ? n - 999999999999 : 0;
        res += n > 999999999999999 ? n - 999999999999999 : 0;
        return res;
    }
};