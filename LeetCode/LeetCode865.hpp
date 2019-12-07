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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int d = depth(root->left) - depth(root->right);
        return d == 0 ? root : subtreeWithAllDeepest(d>0 ? root->left : root->right);
    }
    int depth(TreeNode* root) {
    	return !root ? 0: max(depth(root->left), depth(root->right))+1;
    }
};