class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        for(int d=A.size()-1;d>0;d--) {
        	for(int i=0;i<A.size()-d;i++) {
        		if(A[i]<=A[i+d]) return d;
        	}
        }
        return 0;
    }
};