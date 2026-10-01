class Solution {
public:
    set<string> st;
    void helper(string& s){
        int r = s.find('}');
        if (r == string::npos) {
            st.insert(s);
            return;
        }
        int l = s.rfind('{', r);
        string left = s.substr(0, l);
        string right = s.substr(r+1);
        string inside = s.substr(l+1, r-l-1);
        string part;
        stringstream ss(inside);

        while (getline(ss, part, ',')) {
            string temp = left + part + right;
            helper(temp);
        }
    }

    vector<string> braceExpansionII(string expression) {
        helper(expression);
        return vector<string>(st.begin(), st.end());
    }
};