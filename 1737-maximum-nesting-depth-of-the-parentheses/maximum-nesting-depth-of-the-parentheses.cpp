class Solution {
public:
    int maxDepth(string s) {
        int open = 0, res = 0;
        for (char ch: s) {
            if (ch == '(') open++;
            else if (ch == ')') {
                res = max(res, open--);
            }
        }
        return res;
    }
};