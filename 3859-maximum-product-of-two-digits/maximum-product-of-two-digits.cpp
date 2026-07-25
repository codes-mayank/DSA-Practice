class Solution {
public:
    int maxProduct(int n) {
        int largest = 0, slargest = 0;
        while (n){
            int digit = n%10;
            n /= 10;
            if (digit >= largest) {
                slargest = largest;
                largest = digit;
            }
            if (digit > slargest && digit != largest) slargest = digit;
        }
        return largest * slargest;
    }
};