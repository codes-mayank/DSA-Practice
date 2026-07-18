class Solution {
public:
    int gcd(int a, int b){
        if (a==0) return b;
        if (b==0) return a;
        if (a>b) return gcd(a%b, b);
        return gcd(a, b%a);
    }

    int findGCD(vector<int>& nums) {
        int mini = *(min_element(nums.begin(), nums.end()));
        int maxi = *(max_element(nums.begin(), nums.end()));
        return gcd(mini, maxi);
    }
};