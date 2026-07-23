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
    vector<int> helper(TreeNode* root, int& ans){
        if (root==NULL) return {0, INT_MAX, INT_MIN};
        vector<int> left = helper(root->left, ans);
        vector<int> right = helper(root->right, ans);
        if (left[2]<root->val && right[1]>root->val){
            int val = left[0]+right[0]+root->val;
            ans = max(ans, val);
            return {val, min(left[1], root->val), max(right[2], root->val)};
        }
        else {
            return {0, INT_MIN, INT_MAX};
        }
    }

    int maxSumBST(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};