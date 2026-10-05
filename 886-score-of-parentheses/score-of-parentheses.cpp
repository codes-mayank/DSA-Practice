class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') {
                st.push(-1);
            }
            else {
                if (st.top() == -1) {
                    st.pop();
                    st.push(1);
                }
                else {
                    int sum = 0;
                    while (st.top() != -1) {
                        sum += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(sum * 2);
                }
            }
        }
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};