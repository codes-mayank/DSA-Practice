class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, n = nums.size(), h = n-1, ans = INT_MAX;
        while (l<=h){
            int mid = (l+h)>>1;
            ans = min(ans, nums[mid]);
            if (nums[l]<=nums[mid] && nums[mid]>=nums[h]) l = mid+1;
            else h = mid-1;
        }
        return ans;
    }
};