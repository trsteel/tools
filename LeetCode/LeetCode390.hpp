class Solution {
public:
    int lastRemaining(int n) {
        return n==1?1:((1+(n>>1)-lastRemaining(n>>1))<<1);
    }
};