class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        auto get_nums = [](stack<int>& s) {
        	int x = s.top();
			s.pop();
			int y = s.top();
			s.pop();
			return make_pair(x, y);
        };
        for(auto& t: tokens) {
        	if(t=="+"){
    			auto p = get_nums(st);
    			st.push(p.second+p.first);
    		} else if (t=="-"){
    			auto p = get_nums(st);
    			st.push(p.second-p.first);
    		} else if (t=="*"){
    			auto p = get_nums(st);
    			st.push(p.second*p.first);
    		} else if (t=="/"){
    			auto p = get_nums(st);
    			st.push(p.second/p.first);
    		} else {
    			st.push(atoi(t.c_str()));
        	}
        }
        return st.top();
    }
};