/*
 * 回溯算法超时了
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int end_index = -1;
        for(int i=0;i<wordList.size();i++) {
        	if(wordList[i] == endWord) end_index = i;
        }
        if(end_index==-1) return res;

        map<int, vector<int>> index;
        for(int i=0;i<wordList.size()-1;i++) {
        	for(int j=i+1;j<wordList.size();j++) {
        		if (is_ladder(wordList[i], wordList[j])) {
        			index[i].push_back(j);
        			index[j].push_back(i);
        		}
        	}
        }
        int shortest = -1;
        for(int i=0;i<wordList.size();i++) {
        	if (!is_ladder(beginWord, wordList[i])) continue;
        	vector<string> cache;
        	cache.push_back(beginWord);
        	cache.push_back(wordList[i]);
        	map<int, bool> visited;
        	visited[i] = true;
        	backstrap(wordList, end_index, shortest, index, i, visited, cache, res);
        }
        vector<vector<string>> ans;
        for(auto& r: res) {
        	if(r.size()==shortest) ans.push_back(r);
        }
        return ans;
    }
    void backstrap(vector<string>& wordList, int end, int& shortest, map<int, vector<int>>& index, int cur, map<int, bool>& visited, vector<string>& cache, vector<vector<string>>& res){
    	if(cur==end) {
    		if(cache.size()<=shortest) {
    			shortest = cache.size();
    			res.push_back(cache);
    		}
    		
    		return;
    	}
    	if(cache.size()>shortest) return;
    	for(auto i: index[cur]) {
    		if(visited[i]) continue;
    		cache.push_back(wordList[i]);
    		visited[i] = true;
    		backstrap(wordList, end, shortest, index, i, visited, cache, res);
    		cache.pop_back();
    		visited[i] = false;
    	}
    }

    bool is_ladder(string a, string b) {
    	if (a.size() != b.size()) return false;
    	int diff = 0;
    	for(int i=0;i<a.size();i++) {
    		if(a[i] != b[i]) {
    			diff++;
    			if(diff > 1) return false;
    		}
    	}
    	return diff == 1;
    }
};