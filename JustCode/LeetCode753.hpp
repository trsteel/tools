class Solution {
public:
    string crackSafe(int n, int k) {
        string res(n, '0');
        unordered_set<string> visited;
        visited.insert(res);
        for(int i=0;i<pow(k, n);i++) {
        	string pre = res.substr(res.size()-n+1, n-1);
        	for(int j=k-1;j>=0;j--) {
        		string now = pre + to_string(j);
        		if(!visited.count(now)){
        			visited.insert(now);
        			res += to_string(j);
        			break;
        		}
        	}
        }
        return res;
    }
};