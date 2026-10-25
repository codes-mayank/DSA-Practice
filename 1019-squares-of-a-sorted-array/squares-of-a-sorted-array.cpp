class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), i, p, j;
        vector<int> ans;
        for (i=0; i<n; i++){
            if (nums[i] >=0){
                p = i;
                break;
            }
        }
        if (p>0) j= p-1;
        for (i=0; i<n; i++){
            nums[i] = nums[i]*nums[i];
        }
        while (j>=0 && p< n){
            if (nums[p]<= nums[j]){
                ans.push_back(nums[p]);
                p++;
            }
            else{
                ans.push_back(nums[j]);
                j--;
            }
        }
        while (j>=0){
            ans.push_back(nums[j]);
            j--;
        }
        while (p<n){
            ans.push_back(nums[p]);
            p++;
        }
        return ans;

    }
};