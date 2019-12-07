class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
    	vector<int> res, squs;
    	for(int i=0;i<A.size();i++)
    		squs.push_back(A[i]*A[i]);
        int i=0, j=A.size()-1;
        while(i<=j) {
        	if(squs[i]<squs[j]) {
        		res.insert(res.begin(), squs[j]);
        		j--;
        	} else if(squs[i]>squs[j]) {
        		res.insert(res.begin(), squs[i]);
        		i++;
        	} else {
        		res.insert(res.begin(), squs[i]);
        		if(i!=j) res.insert(res.begin(), squs[j]);
        		i++;
        		j--;
        	}
        }
        return res;
    }
};