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
        vector<int>res;
        if (!root) return res;
        TreeNode* node = root;
        while (node){
            if (node->left){
                TreeNode* leftEnd = node->left;
                while (leftEnd->right && leftEnd->right!=node){
                    leftEnd = leftEnd->right;
                }
                if (!leftEnd->right){
                    leftEnd->right = node;
                    node = node->left;
                }
                else {
                    leftEnd->right = NULL;
                    res.push_back(node->val);
                    node = node->right;
                }

            }
            else {
                res.push_back(node->val);
                node = node->right;
            }
        }
        return res;
    }
};