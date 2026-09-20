class Solution {
public:
    int reverseDegree(string s) {
        int res = 0;
        for (int i=0; i<s.size(); i++){
            int reversed = 'z' - s[i] + 1;
            res += reversed * (i+1);
            cout << reversed * (i+1) << endl;
        }
        return res;
    }
};