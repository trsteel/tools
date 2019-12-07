class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.empty()) return 0;
        int last_index = 0, last_count = 1;
        int res = 0;
        for(int i=1;i<chars.size();i++) {
            if(chars[i]==chars[last_index]) last_count++;
            else {
                compress(chars, res, chars[last_index], last_count);
                last_count = 1;
                last_index = i;
            }
        }
        compress(chars, res, chars[last_index], last_count);
        return res;
    }
    void compress(vector<char>& chars, int& start, char c, int count) {
        chars[start++] = c;
        if(count==1) return;
        for(char& ch: to_string(count)){
            chars[start++] = ch;
        }
    }
};