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
    TreeNode* build(int& postStart, int inStart, int inEnd, unordered_map<int, int>& mp,  vector<int>& preorder, vector<int>& inorder){
        if (inStart>inEnd || postStart<0) return NULL;
        TreeNode* node = new TreeNode(preorder[postStart--]);
        if (inStart==inEnd){
            return node;
        }
        node->right = build(postStart, mp[node->val]+1, inEnd, mp, preorder, inorder);
        node->left = build(postStart, inStart, mp[node->val]-1, mp, preorder, inorder);
        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for (int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        int postStart = n-1;
        return build(postStart, 0, n-1, mp, postorder, inorder);
    }
};