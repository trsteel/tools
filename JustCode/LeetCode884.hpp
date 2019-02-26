class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        map<string, int> m;
        for(auto& str: split(A, ' ')) m[str]++;
    	for(auto& str: split(B, ' ')) m[str]++;
    	vector<string> res;
    	for(auto& it: m){
    		if(it.second==1) 
    			res.push_back(it.first);
    	}
    	return res;
    }
    vector<string> split(string& s, char sep) {
    	vector<string> res;
    	string cur = "";
    	for(char& c: s) {
    		if(c==sep && cur.size()>0) {
    			res.push_back(cur);
    			cur = "";
    		} else {
    			cur += c;
    		}
    	}
    	if(cur.size()>0) res.push_back(cur);
    	return res;
    }
};