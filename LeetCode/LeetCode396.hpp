class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long sum=0, f=0;
        for(int i=0;i<A.size();i++) {
        	sum += A[i];
        	f +=i*A[i];
        }
        long max_diff=0, diff=0;
        for(int i=A.size()-1;i>0;i--) {
        	diff += sum-A.size()*A[i];
        	if(diff > max_diff) max_diff = diff;
        }
        return f+max_diff;
    }
};