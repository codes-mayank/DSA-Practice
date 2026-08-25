class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        long long num = 1;
        while (true){
            if (st.find(num*k)==st.end()) return num*k;
            num++;
        }
        return -1;
    }
};