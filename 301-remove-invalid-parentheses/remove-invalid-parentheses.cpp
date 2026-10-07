class Solution {
public:
    void helper(int i, int open, int k, string& par, string& s, unordered_set<string>& res) {
        if (k < 0 || open < 0) return;
        if (i == s.size()) {
            if (open == 0 && k==0) res.insert(par);
            return;
        }
        par += s[i];
        if (s[i] == '(') {
            helper(i+1, open+1, k, par, s, res);
        }
        else if (s[i] == ')') {
            helper(i+1, open-1, k, par, s, res);
        }
        else helper(i+1, open, k, par, s, res);
        par.pop_back();
        if (s[i] == '(' || s[i] == ')') {
            
            helper(i+1, open, k-1, par, s, res);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        string par = "";
        int open = 0, ans = 0;
        for (char ch: s) {
            if (ch == '(') open++;
            else if (ch == ')') open--;
            if (open < 0) {
                open = 0;
                ans++;
            }
        }
        cout << open<<endl;
        ans += open;
        cout << ans;
        helper(0, 0, ans, par, s, st);
        vector<string> res(st.begin(), st.end());
        if (res.size() == 0) res.push_back("");
        return res;
    }
};