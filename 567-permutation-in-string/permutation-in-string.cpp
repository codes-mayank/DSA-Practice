class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) return false;
        vector<int> s11(26), s22(26);
        for (int i=0; i<s1.size(); i++){
            s11[s1[i]-'a']++;
            s22[s2[i]-'a']++;
        }
        if (s11==s22) return true;
        for (int i=s1.size(); i<s2.size(); i++){
            s22[s2[i-s1.size()]-'a']--;
            s22[s2[i]-'a']++;
            if (s11==s22) return true;
        }
        return false;
    }
};