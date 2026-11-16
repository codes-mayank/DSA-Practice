class Solution {
public:
    string sum(string s) {
        long long ans = 0;
        for (char ch : s) {
            ans += ch - '0';
        }
        string res = to_string(ans);
        return res;
    }

    string digitSum(string s, int k) {
        string ans = "";
        while (s.size() > k) {
            string temp = "";
            for (int i=0; i<s.size(); i+= k) {
                long long ans = 0;
                for (int j=i; j<k+i && j<s.size(); j++) {
                    ans += s[j] - '0';
                }
                temp += to_string(ans);
            }
            s = temp;
        }
        return s;
    }
};