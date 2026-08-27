class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), l = 0, r = 0, black = 0;
        int maxi = 0;
        for (r=0; r<k; r++) if (blocks[r]=='B') black++;
        maxi = black;
        while (r<n) {
            if (blocks[r]=='B') black++;
            if (blocks[l++]=='B') black--;
            maxi = max(maxi, black);
            r++;
        }
        return k-maxi;
    }
};