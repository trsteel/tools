class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> ans;
        vector<int> xt, yt;
        xt.push_back(1);
        if(x>1) {
	        while(xt.back()*x<=bound) {
	        	xt.push_back(xt.back()*x);
	        }
	    }
        yt.push_back(1);
        if(y>1){
	        while(yt.back()*y<=bound) {
	        	yt.push_back(yt.back()*y);
	        }
	    }
        for(int i=0;i<xt.size();i++) {
        	for(int j=0;j<yt.size();j++) {
        		if(xt[i]+yt[j]>bound) break;
        		ans.insert(xt[i]+yt[j]);
			}
        }
        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};