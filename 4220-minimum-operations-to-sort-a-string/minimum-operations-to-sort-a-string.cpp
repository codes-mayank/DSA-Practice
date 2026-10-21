class Solution {
public:
    int minOperations(string s) {
        if (is_sorted(s.begin(), s.end())) return 0;
        int mini = 0, maxi = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] < s[mini]) mini = i;
            if (s[i] >= s[maxi]) maxi = i;
        }
        cout << mini <<endl<<maxi;
        if (mini==0 || maxi==s.size()-1) return 1;
        if (!(mini == s.size()-1 && maxi == 0)) return 2;
        if (s.size()==2) return -1;
        return 3;
    }
};