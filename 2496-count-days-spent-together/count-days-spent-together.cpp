class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> pre(13);
        pre[0] = 0;
        for (int i=1; i<=12; i++) pre[i] = pre[i-1] + months[i];
        int a1 = pre[stoi(arriveAlice.substr(0, 2))-1] + stoi(arriveAlice.substr(3, 2));
        int a2 = pre[stoi(arriveBob.substr(0, 2))-1] + stoi(arriveBob.substr(3, 2));
        int l1 = pre[stoi(leaveAlice.substr(0, 2))-1] + stoi(leaveAlice.substr(3, 2));
        int l2 = pre[stoi(leaveBob.substr(0, 2))-1] + stoi(leaveBob.substr(3, 2));
        return max(0, min(l1, l2) - max(a1, a2) + 1);
    }
};