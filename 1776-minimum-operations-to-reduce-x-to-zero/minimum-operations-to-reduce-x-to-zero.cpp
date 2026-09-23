class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum = 0;
        for (int i: nums) sum += i;
        long long remaining = sum - x;
        if (remaining == 0) return nums.size();
        long long temp = 0;
        int l = 0;
        int size = 0;
        for (int r=0; r<nums.size(); r++){
            temp += nums[r];
            while (l<r && temp>remaining){
                temp -= nums[l++];
            }
            if (temp == remaining) size = max(size, r-l+1);
        }
        return size != 0 ? nums.size() - size : -1;
    }
};