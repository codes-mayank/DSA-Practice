class Solution {
public:
    int search(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0, r = n-1;
        while (l <= r) {
            int mid = l + (r-l) /2;
            if (arr[mid] == k) return mid;
            if (arr[l] <= arr[mid]) {
                if (arr[mid] >= k && arr[l] <= k) r = mid-1;
                else l = mid+1;
            }
            else {
                if (arr[mid] <= k && arr[r] >= k) l = mid+1;
                else r = mid-1;
            }
        }
        return -1;
    }
};