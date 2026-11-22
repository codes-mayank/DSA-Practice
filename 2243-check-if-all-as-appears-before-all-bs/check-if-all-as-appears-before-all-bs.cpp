class Solution {
public:
    bool checkString(string s) {
        int a = -1, b = -1;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == 'a') {
                a = i;
            }
            if (s[i] == 'b') {
                if (b == -1) b = i;
            }
        }
        if (b == -1) return true;
        return a <= b;
    }
};