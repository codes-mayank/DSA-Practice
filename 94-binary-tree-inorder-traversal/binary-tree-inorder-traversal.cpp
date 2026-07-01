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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> inorder;
        if (!root) return inorder;
        TreeNode* node = root;
        while(true){
            if (node!=NULL){
                nodes.push(node);
                node = node->left;
            }
            else {
                if (nodes.empty()) break;
                node = nodes.top();
                nodes.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};