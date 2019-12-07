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
    int widthOfBinaryTree(TreeNode* root) {
        deque<TreeNode*> st1, st2;
        st1.push_back(root);
        int res=0;
        while(!st1.empty()) {
            res = max(res, (int)st1.size());
            exchange(st1, st2);
            res = max(res, (int)st2.size());
            exchange(st2, st1);
        }
        return res;
    }

    void exchange(deque<TreeNode*>& st1, deque<TreeNode*>& st2){
        bool prefix_null = true;
        while(!st1.empty()) {
            if(!st1.front()) {
                if(!prefix_null) {
                    st2.push_back(nullptr);
                    st2.push_back(nullptr);
                }
            } else {
                bool child_null = !st1.front()->left && !st1.front()->right;
                if(prefix_null) {
                    if(!child_null) {
                        prefix_null = false;
                        if(st1.front()->left) 
                            st2.push_back(st1.front()->left);
                        st2.push_back(st1.front()->right);
                    }
                } else {
                    st2.push_back(st1.front()->left);
                    st2.push_back(st1.front()->right);
                }
            }
            st1.pop_front();
        }
        while(!st2.empty() && !st2.back()) st2.pop_back();
    }
};