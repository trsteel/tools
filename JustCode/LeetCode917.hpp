class Solution {
public:
    string reverseOnlyLetters(string S) {
        stack<char> st;
        for(char& c: S) {
        	if(is_letter(c)) st.push(c);
        }
        string res;
        for(char& c: S) {
        	if(is_letter(c)) {
        		res += st.top();
        		st.pop();
        	} else {
        		res += c;
        	}
        }
        return res;
    }
    
    bool is_letter(char c) {
    	return (c>='A' && c<='Z') || (c>='a' && c<='z');
    }
};