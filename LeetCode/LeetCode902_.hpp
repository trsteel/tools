class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int p = 1, res = 0;
        while(N>0) {
            int ans = count(D, to_string(N%10));
            if(p==1) ans--;
            res += ans*p;
            N/=10;
            p*=D.size();
        }
        return res;
    }
    int count(vector<string>& d, string num) {
        int ans = 1;
        for(string s: d) {
            if(s>num) break;
            ans ++;
        }
        return ans;
    }
};