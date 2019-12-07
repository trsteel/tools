class Solution {
public:
    int distinctSubseqII(string S) {
        vector<int> end(26, 0);
        int res = 1, pre=0, mod=1e9+7;
        for(char& c: S) {
        	pre = res;
        	res = ((res<<1)%mod - end[c-'a'] + mod) % mod;
        	end[c-'a'] = pre;
        }
        return res-1;
    }
};