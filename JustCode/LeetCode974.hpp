class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> counts(K);
        counts[0] = 1;
        int pre = 0, res = 0;
        for(int a: A) {
            pre = (pre+a%K+K) % K;
            res += counts[pre]++;
        }
        return res;
    }
};