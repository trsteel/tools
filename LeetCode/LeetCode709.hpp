class Solution {
public:
    string toLowerCase(string str) {
        string res;
        for(char& c: str) {
        	res += (c<='Z' && c>='A') ? (c-'A'+'a'): c;
        }
        return res;
    }
};