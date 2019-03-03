class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if(A.size()<3) return false;
        if(A[0]>A[1]) return false;
        bool increase = true;
        for(int i=1;i<A.size();i++) {
            if(A[i-1]==A[i]) return false;
            if(A[i-1]<A[i] && !increase) return false;
            if(A[i-1]>A[i]) {
                if(increase) increase = false;
            }
        }
        return !increase;
    }
};