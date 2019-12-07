class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for(auto& email: emails) {
        	string real;
        	bool is_domain = false;
        	bool has_plus = false;
        	for(char c: email) {
        		if(is_domain) {
        			real += c;
        		} else {
        			if(c=='@') {
        				real += c;
        				is_domain = true;
        			}

        			if(has_plus || c=='.') {
        				continue;
        			} else if (c=='+') {
        				has_plus = true;
        			} else {
        				real += c;
        			}
        		}
        	}
        	ans.insert(real);
        }
        return ans.size();
    }
};