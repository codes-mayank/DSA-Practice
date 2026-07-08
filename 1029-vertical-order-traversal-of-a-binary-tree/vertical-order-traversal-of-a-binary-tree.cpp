/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<pair<int, int>, multiset<int>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        if (!root) return {};
        int mini = INT_MAX, maxi = INT_MIN;
        q.push({root,{ 0, 0}});
        while (!q.empty()){
            TreeNode* node = q.front().first;
            int line = q.front().second.first;
            int level = q.front().second.second;
            mini = min(mini, line);
            maxi = max(maxi, line);
            q.pop();
            mp[{line, level}].insert(node->val);
            if (node->left) q.push({node->left, {line-1, level+1}});
            if (node->right) q.push({node->right,{line+1, level+1}});
        }
        vector<vector<int>> res((maxi-mini+1));
        for (auto& it: mp){
            for (int i: it.second){
                res[it.first.first-mini].push_back(i);
            }
        }
        return res;
    }
};