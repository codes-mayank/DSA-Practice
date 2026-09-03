class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int mini = INT_MAX;
        bool isOdd = false;
        for (int i: nums1) {
            mini = min(mini, i);
            if (i & 1) isOdd = true;
        }
        if (mini & 1) return true;
        if (isOdd) return false;
        return true;
    }
};