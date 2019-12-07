// 对每一个元素分析，出现为子序列最大值和最小值的情况。
class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        if(A.size()<2) return 0;
        sort(A.begin(), A.end());
        long c = 1, res = 0, mod = 1e9+7;
        for(int i=0;i<A.size();i++, c=(c<<1)%mod) {
        	res = (res + A[i]*c -A[A.size()-i-1]*c) % mod;
        }
        return (res+mod) % mod;
    }
};