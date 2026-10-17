class Solution {
public:
    int sumD(int n) {
        // Handle negative numbers by taking absolute value
        if (n < 0) n = -n;
        
        int sum = 0;
        while (n != 0) {
            sum += n % 10;  // Add the last digit to sum
            n /= 10;        // Remove the last digit
        }
        return sum;
    }


    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>sorted = nums;
        sort(sorted.begin(), sorted.end(), [&](int a, int b){
            int x = sumD(a);
            int y = sumD(b);
            if (x != y) return x <= y;
            return a <= b;
        });
        unordered_map<int, int> mp;
        for (int i=0; i<n; i++) {
            mp[sorted[i]] = i;
        }
        int cycles = 0;
        vector<int> vis(n);
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                cycles++;
                int j = i;
                while (!vis[j]) {
                    vis[j] = 1;
                    j = mp[nums[j]];
                }
            }
        }
        return n - cycles;
    }
};