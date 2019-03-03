class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        unordered_set<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37};
        int ans = 0;
        for(int i=L;i<=R;i++) {
            if(primes.count(getOne(i))) {
                ++ans;
            }
        }
        return ans;
    }

    int getOne(int n) {
        int res = 0;
        while(n>0) {
            if(n%2==1) ++res;
            n>>=1;
        }
        return res;
    }
};