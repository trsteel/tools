class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
        	return 0;
        }
        vector<long long> dp(s.size()+2, 0);
        dp[s.size()] = 1;
        for(int i=s.size()-1;i>=0;i--) {
        	if (i < s.size()-1) {
        		dp[i] = numDecodings(s[i], s[i+1]) * dp[i+2];
        		dp[i] %= 1000000007;
        	}
        	dp[i] += numDecodings(s[i]) * dp[i+1] % 1000000007;
        	dp[i] %= 1000000007;
        }
        return dp[0];
    }

    long long numDecodings(char c) {
    	if(c=='*') {
    		return 9;
    	} else if(c=='0') {
    		return 0;
    	} else {
    		return 1;
    	}
    }

    long long numDecodings(char c1, char c2) {
    	if (c1 == '*') {
    		if (c2 == '*') {
    			return 15;
    		} else if (c2 > '6') {
    			return 1;
    		} else {
    			return 2;
    		}
    	} else if (c1 > '2') {
    		return 0;
    	} else if (c1 > '1') {
    		if (c2 == '*') {
    			return 6;
    		} else if (c2 > '6') {
    			return 0;
    		} else {
    			return 1;
    		}
    	} else if (c1 > '0') {
    		if (c2 == '*') {
    			return 9;
    		} else {
    			return 1;
    		}
    	} else {
    		return 0;
    	}
    }
};