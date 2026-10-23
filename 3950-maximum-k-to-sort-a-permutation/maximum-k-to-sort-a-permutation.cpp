class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> temp;
        bool swapped = false;
        for (int i=0; i<n; i++) {
            if (nums[i] == i) vis[i] = true;
            else if (!vis[i]) {
                swapped = true;
                int j = nums[i];
                temp.push_back(nums[i]);
                vis[i] = true;
                while (j != i){
                    vis[j] = true;
                    temp.push_back(nums[j]);
                    j = nums[j];
                }
            }
        }
        if (!swapped) return 0;
        int ans = temp[0];
        for (int i=1; i<temp.size(); i++) ans = ans & temp[i];
        return ans;
    }
};