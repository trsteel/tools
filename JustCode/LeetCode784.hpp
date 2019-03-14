class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        vector<char> cache(S.size());
        dfs(S, res, cache, 0);
        return res;
    }
    void dfs(string& S, vector<string>& res, vector<char> cache, int start) {
        while(start<S.size()&&is_digit(S[start])) {
            cache[start] = S[start];
            start++;
        }
        if(start>=S.size()) {
            string r;
            for(char c: cache) r+=c;
            res.push_back(r);
            return;
        }
        cache[start] = S[start];
        dfs(S, res, cache, start+1);
        cache[start] = reverse_letter(S[start]);
        dfs(S, res, cache, start+1);
    }
    bool is_digit(char c) {
        return c >='0' && c<='9';
    }
    char reverse_letter(char c) {
        if(c>='A' && c<='Z') return c-'A'+'a';
        else return c-'a'+'A';
    }
};