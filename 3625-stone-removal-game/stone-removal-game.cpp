class Solution {
public:
    bool canAliceWin(int n) {
        bool win = false;
        for (int i=10; i>=1; i--) {
            if (n<i) return win;
            n -= i;
            win = !win;
        }
        return false;
    }
};