class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        long ans = 0, mod = 1e9+7;
        for(int i=0;i<A.size();i++) {
        	int l = 1;
        	for(int j=i-1;j>=0;j--)
        		if(A[j]>A[i]) l++;
        		else break;
        	int r = 1;
        	for(int j=i+1;j<A.size();j++)
        		if(A[j]>=A[i]) r++;
        		else break;
        	ans += (l*r*A[i]) % mod;
        	ans %= mod;
        }
        return ans;
    }
};