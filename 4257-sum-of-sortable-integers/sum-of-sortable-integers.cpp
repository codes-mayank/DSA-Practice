class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            if (count > 1)
                return false;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> divisors;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);

                if (i != n / i) {
                    divisors.push_back(n / i);
                }
            }
        }
        for (int i : divisors)
            cout << i << endl;

        for (int divisor : divisors) {
            bool flag = true;
            int prevMax = INT_MIN;

            for (int j = 0; j < n; j += divisor) {
                vector<int> res(nums.begin() + j, nums.begin() + j + divisor);

                if (!check(res)) {
                    flag = false;
                    break;
                }
                int mn = *min_element(res.begin(), res.end());
                int mx = *max_element(res.begin(), res.end());
                if (prevMax > mn) {
                    flag = false;
                    break;
                }

                prevMax = mx;
            }

            if (flag)
                ans += divisor;
        }

        return ans;
    }
};