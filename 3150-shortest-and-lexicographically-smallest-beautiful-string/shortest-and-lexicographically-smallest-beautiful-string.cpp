class Solution {
public:


    string shortestBeautifulSubstring(string s, int k) {
        string ans = "";
        int l = 0, r = 0, one = 0;
        for (r=0; r<s.size(); r++){
            if (s[r]=='1') one++;
            while (one>k){
                if (s[l++]=='1') one--;
            }
            if (one==k){
                while (s[l]=='0') l++;
                string sub = s.substr(l, r-l+1);
                if (ans.empty() || ans.size()>sub.size() || ans.size()==sub.size() && sub<ans)
                    ans = sub;
            }
        }
        return ans;
    }
};