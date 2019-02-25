class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
    	if(A.size()==0) return 0;
        sort(A.begin(), A.end());
        int ans = 0, max_cnt=A[0];
        for(int i=1;i<A.size();i++) {
        	int a = A[i];
        	if(a>max_cnt) {
        		max_cnt = a;
        		continue;
        	}
        	max_cnt++;
        	ans += max_cnt - a;
        }
        return ans;
    }
};