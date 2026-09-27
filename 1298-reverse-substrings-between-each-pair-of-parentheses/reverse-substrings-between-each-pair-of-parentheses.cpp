class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        stack<int> st;
        for (int i=0; i<n; i++){
            if (s[i] == '(') {
                st.push(i);
            }
            else if (s[i] == ')') {
                reverse(s.begin()+st.top()+1, s.begin()+i);
                st.pop();
            }
        }
        string ans = "";
        for (char ch: s) if (ch != '(' && ch != ')') ans += ch;
        return ans;
    }
};