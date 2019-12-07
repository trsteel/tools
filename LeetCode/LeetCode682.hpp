class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        int ans = 0;
        for(auto &op: ops) {
            if(op=="+") {
                int t = st.top();
                st.pop();
                int s = st.top()+t;
                st.push(t);
                ans += s;
                st.push(s);
            } else if(op=="D") {
                int t = st.top()*2;
                ans += t;
                st.push(t);
            } else if(op=="C") {
                ans -= st.top();
                st.pop();
            } else {
                int t = stoi(op);
                ans += t;
                st.push(t);
            }
        }
        return ans;
    }
};