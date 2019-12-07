class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> mos = {
            ".-","-...","-.-.","-..",".",
            "..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",".--.",
            "--.-",".-.","...","-","..-","...-",
            ".--","-..-","-.--","--.."
        };
        unordered_set<string> ans;
        for(auto& word: words) {
            string cur;
            for(char c: word) cur += mos[c-'a'];
            ans.insert(cur);
        }
        return ans.size();
    }
};