class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> s(words.begin(), words.end());
        vector<string> res;
        for(string w: words) {
        	vector<int> dp(w.size()+1, 0);
        	dp[0] = 1;
        	for(int i=0;i<w.size();i++) {
        		if(dp[i]==0) continue;
        		for(int j=i+1;j<=w.size();j++) {
        			if(j-i<w.size() && s.count(w.substr(i, j-i))) {
        				dp[j] = 1;
        			} 
        		}
        		if(dp[w.size()]) {
        			res.push_back(w);
        			break;
        		}
        	}
        }
        return res;
    }
};