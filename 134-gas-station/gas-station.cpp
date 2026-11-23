class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_g = 0, total_c = 0, cur = 0, start = 0;
        for (int i=0; i<cost.size(); i++) {
            total_g += gas[i];
            total_c += cost[i];
            cur += gas[i] - cost[i];
            if (cur < 0) {
                cur = 0;
                start = i+1;
            }
        }
        return total_c > total_g ? -1 : start;
    }
};