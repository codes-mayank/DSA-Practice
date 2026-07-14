class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>st; 
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                int l = j+1, r = n-1;
                while (l<r){
                    double sum = 0;
                    vector<int>v{i, j, l, r};
                    for (int x: v){
                        sum += nums[x];
                        if (sum>INT_MAX){
                            r--;
                            continue;
                        }
                    }
                    if (sum == target){
                        st.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                    }
                    else if (sum > target){
                        r--;
                    }
                    else l++;
                }
            }
        }
        vector<vector<int>> res(st.begin(), st.end());
        return res;
    }
};