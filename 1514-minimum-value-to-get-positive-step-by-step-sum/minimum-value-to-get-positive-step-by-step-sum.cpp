class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n);
        for (int i=0; i<n; i++){
            if (i>0){
                prefixSum[i] = nums[i] + prefixSum[i-1];
            }
            else prefixSum[i] = nums[i];
        }
        int minValue = 1;
        for (int i: prefixSum){
            minValue = max(minValue, 1 - i);
        }
        return minValue;
    }
};