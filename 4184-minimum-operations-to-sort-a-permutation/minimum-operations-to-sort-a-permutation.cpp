class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0, c2 = 0, idx = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] < nums[(i+1)%n]) c1++;
            else c2++;
            if (nums[i] == 0) idx = i;
        }
        if (c1 > 1 && c2 > 1) return -1;
        int res = 0;
        if (c2 == 1) {
            res = n-idx+2;
            res = min(res, idx);
            
        }
        else {
            res = n-idx;
            res = min(res, idx+2);
        }
        return res;
    }
};