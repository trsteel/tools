class TrieNode {
public:
	vector<TrieNode*> next;
	vector<int> list;
	int index;
	TrieNode() {
		next = vector<TrieNode*>(26);
		index = -1;
	}
};
class Trie {
public:
	TrieNode* root;
	Trie(vector<string>& words) {
		root = new TrieNode();
		for(int i=0;i<words.size();i++) {
			add(words[i], i);
		}
	}
	void add(string word, int index) {
		TrieNode* node = root;
		for(int i=word.size()-1;i>=0;i--) {
			int j = word[i] - 'a';
			if(!node->next[j])
				node->next[j] = new TrieNode();
			if(is_palindrome(word, 0, i))
				node->list.push_back(index);
			node = node->next[j];
		}
		node->list.push_back(index);
		node->index = index;
	}
	void search(vector<string> words, int i, vector<vector<int>>& res) {
		TrieNode* node = root;
		for(int j=0;j<words[i].size();j++) {
			if(node->index>=0 && node->index != i && is_palindrome(words[i], j, words[i].size()-1))
				res.push_back({i, node->index});
			node = node->next[words[i][j]-'a'];
			if(!node) return;
		}
		for(int j: node->list) {
			if(i!=j) res.push_back({i, j});
		}
	}

	static bool is_palindrome(string s, int i, int j) {
    	while(i<j) {
    		if(s[i++] != s[j--]) return false;
    	}
    	return true;
    }
};

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        Trie* trie = new Trie(words);
        for(int i=0;i<words.size();i++) {
	        trie->search(words, i, res);
	    }
        return res;	
    }
};