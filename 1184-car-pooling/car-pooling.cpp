class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>prefixSum(1001);
        for (auto it: trips){
            int passengers = it[0];
            int from = it[1];
            int to = it[2];
            prefixSum[from] += passengers;
            prefixSum[to] -= passengers;
        }
        for (int i=0; i<10; i++) {
            cout <<prefixSum[i]<<". ";
        }
        long long sum = 0;
        for (int i: prefixSum){
            sum += i;
            if (sum>capacity) return false;
        }
        return true;
    }
};