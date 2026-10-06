class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int open = 0, ans = 0;
        for (char ch : s) {
            if (ch == '(') open++;
            else {
                if (open == 0) {
                    ans++;
                }
                else {
                    open--;
                }
            }
        }
        ans += open;
        return ans;
    }
};