class Solution {
public:
    int minInsertions(string s) {
        int open = 0, closed = 0;
        for (char ch : s) {
            if (ch == '(') {
                if (closed & 1) {
                    open++;
                    closed--;
                }
                closed += 2;
            }
            else {
                closed--;
                if (closed < 0) {
                    open++;
                    closed = 1;
                }
            }
        }
        return open + closed;
    }
};