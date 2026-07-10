class Solution {
public:
    string longestPalindrome(string s) {
        
        int r = 0, c = 0;
        string newString = "^";
        for (char ch: s){
            newString += '#';
            newString += ch;
        }
        newString += "#$";
        int n = newString.size();
        vector<int>p(n);
        for (int i=1; i<n-1; i++){
            int mirror = 2*c-i;
            if (i<r){
                p[i] = min(r-i, p[mirror]);
            }
            while (newString[i+1+p[i]]==newString[i-1-p[i]])
                p[i]++;
            if (i+p[i]>r){
                c = i;
                r = i+p[i];
            }
        }
        int maxLen = 0, centre = 0;
        for (int i=1; i<n-1; i++){
            if (p[i]>maxLen){
                maxLen = p[i];
                centre = i;
            }
        }
        int start = (centre-maxLen) / 2;
        return s.substr(start, maxLen);
    }
};