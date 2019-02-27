class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<vector<string>>> dp(s.size());
        for(int i=0;i<s.size();i++) {
        	if (is_palindrome(s, 0, i)) {
        		dp[i] = {{s.substr(0, i+1)}};
        	}
        	for(int j=0;j<i;j++) {
        		if(!is_palindrome(s, j+1, i)) {
        			continue;
        		}
    			for(int k=0;k<dp[j].size();k++){
    				vector<string> v;
    				v.assign(dp[j][k].begin(), dp[j][k].end());
    				v.push_back(s.substr(j+1, i-j));
    				dp[i].push_back(v);
    			}
        	}
        }
        return dp.back();
    }

    bool is_palindrome(string s, int i, int j) {
    	while(i<j) {
    		if(s[i++]!=s[j--]) return false;
    	}
    	return true;
    }
};