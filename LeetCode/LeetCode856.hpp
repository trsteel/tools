class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        for(char c: S) {
            if(c=='(') {
                st.push(-1);
                continue;
            }
            int ans = 0, round = 0;
            while(!st.empty()) {
                if(st.top()==-1) {
                    st.pop();
                    break;
                }
                ans += st.top();
                round++;
                st.pop();
            }
            if(round==0) st.push(1);
            else st.push(ans*2);
        }
        int ans = 0;
        while(!st.empty()) ans += st.top(), st.pop();
        return ans;
    }
};