/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        root->left = increasingBST(root->left);
        root->right = increasingBST(root->right);
        if(!root->left) return root;
        TreeNode* node = root->left;
        while(node->right) node = node->right;
        node->right = root;
        node = root->left;
        root->left = NULL;
        return node;
    }
};