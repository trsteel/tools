class Solution {
public:
    Solution(vector<int> w) {
        for(int i=0;i<w.size();i++) {
        	if(i==0) sums.push_back(w[i]);
        	else sums.push_back(sums[i-1]+w[i]);
        }
    }
    
    int pickIndex() {
        int r = rand() % sums.back();
        return upper_bound(sums.begin(), sums.end(), r) - sums.begin();
    }

private:
	vector<int> sums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */