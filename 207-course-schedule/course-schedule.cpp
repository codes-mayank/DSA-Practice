class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses, vector<int>());
        vector<int>inDegree(numCourses, 0);
        for (auto& it: prerequisites){
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }
        queue<int> q;
        for (int i=0; i<numCourses; i++){
            if (inDegree[i]==0) q.push(i);
        }
        vector<int> res;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for (int i: adj[node]){
                inDegree[i]--;
                if (inDegree[i]==0) {
                    q.push(i);
                }
            }
        }
        return res.size()==numCourses ? true : false;
    }
};