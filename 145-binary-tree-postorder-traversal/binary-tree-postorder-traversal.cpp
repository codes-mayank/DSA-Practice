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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        stack<TreeNode*> nodes;
        if (root==NULL) return res;
        TreeNode* node = root;
        while (node || !nodes.empty()){
            if (node){
                nodes.push(node);
                node = node->left;
            }
            else{
                TreeNode* topMost = nodes.top()->right;
                if (!topMost){
                    topMost = nodes.top();
                    nodes.pop();
                    res.push_back(topMost->val);
                    while (!nodes.empty() && nodes.top()->right==topMost){
                        topMost = nodes.top();
                        nodes.pop();
                        res.push_back(topMost->val);
                    }
                }
                else{
                    node = topMost;
                }
            }
        }
        return res;
    }
};