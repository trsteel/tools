class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int direct = 0;
        for(int i=1;i<A.size();i++) {
            int diff = A[i]-A[i-1];
            if(direct==0){
                direct = diff;
            } else if(diff!=0) {
                if(direct<0!=diff<0) return false;
            }
        }
        return true;
    }
};