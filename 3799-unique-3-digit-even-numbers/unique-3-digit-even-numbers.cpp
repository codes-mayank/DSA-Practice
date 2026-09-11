class Solution {
public:

    int totalNumbers(vector<int>& digits) {
        vector<int>freq(10);
        int res = 0;
        for (int digit: digits) freq[digit]++;
        for (int i=1; i<10; i++){
            for (int j=0; j<10; j++){
                for (int k=0; k<10; k += 2){
                    res += freq[i] > 0 && freq[j] > (i==j) && freq[k] > (i==k) + (j==k);
                }
            }
        }
        return res;
    }
};