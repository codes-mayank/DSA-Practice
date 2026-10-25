class Solution {
public:
    void dfs(string word, string beginWord, vector<string>& seq, unordered_map<string, int>& depth, vector<vector<string>>& ans) {
        if (word == beginWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int level = depth[word];
        for(int i=0; i<word.size(); i++){
            string temp = word;
            for (int j=0; j<26; j++){
                temp[i] = char('a' + j);
                if (depth.count(temp) && depth[temp] + 1 == level){
                    seq.push_back(temp);
                    dfs(temp, beginWord, seq, depth, ans);
                    seq.pop_back();
                }
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string, int> depth;
        vector<vector<string>> ans;
        depth[beginWord] = 1;
        unordered_set<string> words;
        for (auto i: wordList){
            words.insert(i);
        }

        q.push(beginWord);
        if (words.find(beginWord)!= words.end()) words.erase(beginWord);
        while (!q.empty()){
            string word = q.front();
            int level = depth[word];
            q.pop();
            if (word == endWord) break;
            int n = word.size();
            for(int i=0; i<n; i++){
                string temp = word;
                for (int j=0; j<26; j++){

                    temp[i] = char('a' + j);
                    if (words.find(temp)!= words.end()){
                        depth[temp] = level + 1;
                        words.erase(temp);
                        q.push(temp);
                    }
                }
            }
        }
        if (depth.count(endWord)) {
            vector<string> seq = {endWord};
            dfs(endWord, beginWord, seq, depth, ans);
        }
        return ans;
    }
};