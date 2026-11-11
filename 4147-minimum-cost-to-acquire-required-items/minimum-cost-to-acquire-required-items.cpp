class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 == 0 && need2 == 0) return 0;
        if (need2 == 0) {
            if (cost1 <= costBoth) return (long long) cost1 * need1;
            else return (long long) costBoth * need1;
        }
        if (need1 == 0) {
            if (cost2 <= costBoth) return (long long) cost2 * need2;
            else return (long long) costBoth * need2;
        }
        long long res = 0;
        if ((long long)(cost1 + cost2) > costBoth) {
            res = (long long) costBoth * min(need1, need2);
            if (need1 == need2) return res;
            else if (need1 > need2) {
                long long diff = need1 - need2;
                res += (long long) diff * min(costBoth, cost1);
            }
            else {
                long long diff = need2 - need1;
                res += (long long) diff * min(costBoth, cost2);
            }
        }
        else {
            res += (long long) need1 * cost1;
            res += (long long) need2 * cost2;
        }
        return res;
    }
};