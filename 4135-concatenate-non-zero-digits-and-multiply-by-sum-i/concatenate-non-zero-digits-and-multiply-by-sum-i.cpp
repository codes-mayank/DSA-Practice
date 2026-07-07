class Solution {
public:
    long long sumAndMultiply(int n) {
        int noOfDigits = 0; long long digits = 0, sum = 0;
        while (n){
            int digit = n%10;
            if (digit){
                digits = (digit * pow(10, noOfDigits++)) + digits;
                sum += digit;
            }
            n /= 10;
        }
        return digits * sum;
    }
};