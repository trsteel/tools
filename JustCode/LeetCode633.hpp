class Solution {
public:
    bool judgeSquareSum(int c) {
        long i = 0;
        while(i*i<=c) {
            long left = c-i*i;
            if(search(left, i, (left>>1)+1)) return true;
            i++;
        }
        return false;
    }

    bool search(long c, int l, int r) {
        while(l<r) {
            long m = (l+r)>>1;
            long m2 = m*m;
            if(m2==c) return true;
            if(m2<c) l = m+1;
            else r = m-1;
        }
        return (long)l*l == c;
    }
};