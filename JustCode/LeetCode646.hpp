class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) -> bool {
        	return a[1]<b[1] || a[1]==b[1] && a[0]<b[0];
        });
        int ans = 0;
        vector<int>& pair = pairs[0];
        for(int i=0;i<pairs.size();i++) {
        	if(i==0 || pairs[i][0] > pair[1]) {
        		pair = pairs[i];
        		ans ++;
        	}
        }
        return ans;
    }
};