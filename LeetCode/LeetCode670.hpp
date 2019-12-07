class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> dp(s.size(), -1);
        int max_pos = s.size() - 1;
        for(int i=s.size()-1;i>=0;i--) {
        	if(s[i] > s[max_pos]) max_pos = i;
        	dp[i] = max_pos;
        }
        for(int i=0;i<s.size();i++) {
        	if(s[dp[i]] != s[i]) {
        		swap(s[i], s[dp[i]]);
        		break;
        	}
        }
        return stoi(s);
    }
};