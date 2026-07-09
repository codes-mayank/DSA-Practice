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
    TreeNode* build(int& preStart, int inStart, int inEnd, unordered_map<int, int>& mp,  vector<int>& preorder, vector<int>& inorder){
        if (inStart>inEnd || preStart>=preorder.size()) return NULL;
        TreeNode* node = new TreeNode(preorder[preStart++]);
        if (inStart==inEnd){
            return node;
        }
        node->left = build(preStart, inStart, mp[node->val]-1, mp, preorder, inorder);
        node->right = build(preStart, mp[node->val]+1, inEnd, mp, preorder, inorder);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = preorder.size();
        for (int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int preStart = 0;
        return build(preStart, 0, n-1, mp, preorder, inorder);
    }
};