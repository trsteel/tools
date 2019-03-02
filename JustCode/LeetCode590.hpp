/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
    	vector<int> res;
    	if(!root) return res;
    	for(Node* node: root->children) {
    		for(auto i: postorder(node))
    			res.push_back(i);
    	}   
    	res.push_back(root->val);
    	return res;
    }
};