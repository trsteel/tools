class TrieNode {
public:
	bool is_end;
	vector<TrieNode*> children;
	TrieNode() {
		is_end = false;
		children = vector<TrieNode*>(26, NULL);
	}
};

class Trie {
public:
	TrieNode* get_root() {
		return root;
	}
	Trie(vector<string>& words) {
		root = new TrieNode();
		for(auto& word: words) {
			add(word);
		}
	}
	void add(const string& word) {
		TrieNode* cur = root;
		for(char c: word) {
			int i = c - 'a';
			if(cur->children[i] == NULL)
				cur->children[i] = new TrieNode();
			cur = cur->children[i];
		}
		cur->is_end = true;
	}
private:
	TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        TrieNode* root = trie->get_root();
        unordered_set<string> res;
        for(int i=0;i<board.size();i++)
        	for(int j=0;j<board[i].size();j++)
        		dfs(board, i, j, root, string(""), res);
        vector<string> ans;
        for(auto& r: res) ans.push_back(r);
        return ans;
    }
    void dfs(vector<vector<char>>& board, int x, int y, TrieNode* root, string word, unordered_set<string>& res) {
    	if(x<0 || x>=board.size() 
    		|| y<0 || y >= board[0].size()
    		|| board[x][y]==' '
    		|| root->children[board[x][y]-'a']==NULL) 
    		return;
    	word = word+board[x][y];
    	root = root->children[board[x][y]-'a'];
    	if(root->is_end) res.insert(word);
    	char c = board[x][y];
    	board[x][y] = ' ';
    	dfs(board, x+1, y, root, word, res);
    	dfs(board, x, y+1, root, word, res);
    	dfs(board, x-1, y, root, word, res);
    	dfs(board, x, y-1, root, word, res);
    	board[x][y] = c;
    }
};