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
    string smallestFromLeaf(TreeNode* root) {
    	if(!root) return "";
        vector<int> ans, cur;
        cur.push_back(root->val);
        dfs(root, ans, cur);
        string s;
        for(int i=ans.size()-1;i>=0;i--)
        	s += char(ans[i]+'a');
        return s;
    }

    void dfs(TreeNode* node, vector<int>& ans, vector<int>& cur) {
    	if(!node->left && !node->right) {
    		if(less(cur, ans)){
    			ans.clear();
    			ans.assign(cur.begin(), cur.end());
    		}
    		return;
    	}
    	if(node->left) {
    		cur.push_back(node->left->val);
    		dfs(node->left, ans, cur);
    		cur.pop_back();
    	}
    	if(node->right) {
    		cur.push_back(node->right->val);
    		dfs(node->right, ans, cur);
    		cur.pop_back();
    	}
    }
    bool less(vector<int> v1, vector<int> v2) {
    	if(v2.size()==0) return true;
    	for(int i=v1.size()-1;i>=0;i--) {
    		int i2 = v2.size()-v1.size()+i;
    		if(i2<0) return false;
    		if(v1[i]==v2[i2]) continue;
    		return v1[i]<v2[i2];
    	}
    	return true;
    }
};