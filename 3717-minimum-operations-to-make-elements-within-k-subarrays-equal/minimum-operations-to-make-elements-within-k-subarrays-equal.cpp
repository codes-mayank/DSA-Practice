class Solution {
public:
    long long minOperations(vector<int>& nums, int k, int x) {
        int n = nums.size();

        if (k <= 0 || x < 0) return -1;
        if (x == 0) return 0;
        if (1LL * k * x > n) return -1;

        // STEP 1: Calculate the cost of every window
        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;
        vector<long long> cost;

        auto balance = [&]() {
            while (low.size() > high.size() + 1) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                int val = *high.begin();
                high.erase(high.begin());
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        for (int i = 0; i < n; i++) {
            // Insert incoming element
            if (low.empty() || nums[i] <= *low.rbegin()) {
                low.insert(nums[i]);
                sumLow += nums[i];
            } else {
                high.insert(nums[i]);
                sumHigh += nums[i];
            }

            // Remove outgoing element
            if (i >= k) {
                int out = nums[i - k];

                auto it = low.find(out);
                if (it != low.end()) {
                    low.erase(it);
                    sumLow -= out;
                } else {
                    high.erase(high.find(out));
                    sumHigh -= out;
                }
            }

            balance();

            // Calculate the window cost
            if (i >= k - 1) {
                long long median = *low.rbegin();

                long long leftCost =
                    median * low.size() - sumLow;

                long long rightCost =
                    sumHigh - median * high.size();

                cost.push_back(leftCost + rightCost);
            }
        }

        // STEP 2: DP to select x non-overlapping windows
        int m = cost.size();
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(m + 1, 0);
        vector<long long> curr(m + 1, INF);

        for (int j = 1; j <= x; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= m; i++) {
                // Option 1: Skip window i-1
                curr[i] = curr[i - 1];

                // Option 2: Take window i-1
                int p = max(0, i - k);

                if (prev[p] != INF) {
                    curr[i] = min(curr[i],
                                  cost[i - 1] + prev[p]);
                }
            }

            prev.swap(curr);
        }

        return prev[m] == INF ? -1 : prev[m];
    }
};