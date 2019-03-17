class Solution {
public:
    /**
     * @param A: an integer sorted array
     * @param target: an integer to be inserted
     * @return: An integer
     */
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        int l=0, r=A.size()-1;
        while(l<r) {
            if(A[l]>=target) return l;
            if(A[r]==target) return r;
            if(A[r]<target) return r+1;
            int m=l + ((r-l)>>1);
            if(A[m]==target) {
                return m;
            } else if(A[m]<target) {
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return A[l]<target?l+1:l;
    }
};