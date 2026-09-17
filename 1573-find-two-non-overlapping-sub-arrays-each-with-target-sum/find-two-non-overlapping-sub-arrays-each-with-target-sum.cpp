class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> prefix(n, INT_MAX), suffix(n, INT_MAX);
        int l = 0, r = 0, res = INT_MAX, sum = 0;
        for (int r=0; r<n; r++){
            sum += arr[r];
            while (sum >= target){
                if (sum==target) res = min(res, r-l+1);
                sum -= arr[l++];
            }
            prefix[r] = res;
        }
        l = n-1; sum = 0; res = INT_MAX;
        for (int r=n-1; r>=0; r--){
            sum += arr[r];
            while (sum >= target){
                if (sum==target) res = min(res, l-r+1);
                sum -= arr[l--];
            }
            suffix[r] = res;
        }
        // for (int i=0; i<n; i++){
        //     cout << prefix[i] << "  " << suffix[i] << endl;
        // }
        res = INT_MAX;
        for (int i=1; i<n; i++){
            if (prefix[i-1]!=INT_MAX && suffix[i]!=INT_MAX) res = min(res, prefix[i-1] + suffix[i]);
        }

        return res != INT_MAX ? res : -1;
    }
};