class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for (int i: nums) {
            if (!((int)(log10(i)+1)&1)) ans++;
        }
        return ans;
    }
};