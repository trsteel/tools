class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<pair<int, int>> st;
        vector<int> res(n, 0);
        for(auto& log: logs) {
        	stringstream ss(log);
        	string s1, s2, s3;
        	getline(ss, s1, ':');
        	getline(ss, s2, ':');
        	getline(ss, s3, ':');
        	int id=stoi(s1), t = stoi(s3);
        	if(s2=="start") {
        		st.push({id, t});
        	} else {
        		int offset = t - st.top().second + 1;
        		res[id] += offset;
        		st.pop();

        		if(!st.empty()) {
	        		res[st.top().first] -= offset;
	        	}
        	}
        }
        return res;
    }
};