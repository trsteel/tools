class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size()) return false;
        if(A==B) {
            unordered_map<char,int> counts;
            for(char c: A) if(++counts[c]>1) return true;
            return false;
        }
        char last_a=' ', last_b = ' ';
        bool has_last = false, changed=false;
        for(int i=0;i<A.size();i++) {
            if(A[i]!=B[i]) {
                if(!has_last) {
                    last_a = A[i];
                    last_b = B[i];
                    has_last = true;
                } else {
                    if(changed) return false;
                    if(last_a!=B[i]||last_b!=A[i]) return false;
                    changed = true;
                }
            }
        }
        return has_last;
    }
};