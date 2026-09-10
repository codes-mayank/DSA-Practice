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
    vector<int> pre(TreeNode* node, int& ans){
        if (!node) return {0, 0};
        vector<int> left = pre(node->left, ans);
        vector<int> right = pre(node->right, ans);
        int lsum = left[0];
        int rsum = right[0];
        if ((lsum + rsum + node->val)/(left[1] + right[1] + 1) == node->val) ans++;
        return {lsum + rsum + node->val, left[1] + right[1] + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        pre(root, ans);
        return ans;
    }
};