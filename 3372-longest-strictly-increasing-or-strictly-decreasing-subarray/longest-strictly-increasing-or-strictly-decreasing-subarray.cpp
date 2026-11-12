class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int ele = nums[0];
        int size = 1;
        int inc = -1;
        for (int i=1; i<nums.size(); i++) {
            if (inc == -1) {
                if (ele < nums[i]) {
                    inc = 1;
                    ele = nums[i];
                    size++;
                    ans = max(size, ans);
                }
                else if (ele > nums[i]) {
                    inc = 0;
                    ele = nums[i];
                    size++;
                    ans = max(ans, size);
                }
            }
            else if (inc == 0) {
                if (ele > nums[i]) {
                    size++;
                    ele = nums[i];
                    
                }
                else if (ele < nums[i]) {
                    size = 2;
                    inc = 1;
                    ele = nums[i];
                }
                else {
                    size = 1;
                    inc = -1;
                    ele = nums[i];
                }
                ans = max(ans, size);
            }
            else {
                if (ele < nums[i]) {
                    size++;
                    
                    ele = nums[i];
                }
                else if (ele > nums[i]) {
                    size = 2;
                    inc = 0;
                    ele = nums[i];
                }
                else {
                    size = 1;
                    inc = -1;
                    ele = nums[i];
                }
                ans = max(ans, size);
            }
        }
        return ans;
    }
};