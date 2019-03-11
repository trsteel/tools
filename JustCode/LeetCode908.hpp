class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if(A.size()<2) return 0;
        int mina=A.front(), maxa = A.front();
        for(int i=1;i<A.size();i++) {
            mina = min(A[i], mina);
            maxa = max(A[i], maxa);
        }
        int ans = maxa-mina;
        return ans>(K<<1)?ans-(K<<1):0;
    }
};