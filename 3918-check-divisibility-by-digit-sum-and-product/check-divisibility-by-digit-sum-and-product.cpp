class Solution {
public:
    bool checkDivisibility(int n) {
        int N = n;
        long long sum = 0;
        long long product = 1;
        while (n){
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }
        if (N % (sum + product) == 0) return true;
        return false;
    }
};