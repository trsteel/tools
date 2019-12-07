class Solution {
public:
    int longestMountain(vector<int>& A) {
    	if(A.size()<3) return 0;
        int start=0, res=0, direct=0;
        bool top = false;
        for(int i=0;i<A.size()-1;i++) {
        	switch(direct) {
    		case 0:
    			if(A[i]<A[i+1]) {
    				direct = 1;
    			} else {
    				start = i+1;
    			}
    			break;
    		case 1:
    			if(A[i]==A[i+1]) {
    				start = i+1;
    				direct = 0;
    			} else if(A[i]>A[i+1]) {
    				direct = -1;
    			}
    			break;
    		case -1:
    			if(A[i]<=A[i+1]) {
    				res = max(res, i-start+1);
    				start = i + (A[i]==A[i+1]?1:0);
    				direct = A[i]==A[i+1]?0:1;
    			}
    			break;
        	}
        	// cout<<i<<start<<top<<endl;
        }
        if(direct==-1 && start<A.size()-1) res = max(res, int(A.size())-start);
        return res;
    }
};