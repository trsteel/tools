class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        vector<int> visited(A.size(), 0);
        int res = 0;
        for(int i=0;i<A.size();i++) {
            if(visited[i]) continue;
            for(int j=i+1;j<A.size();j++) {
                if(is_se(A[i], A[j])) visited[j] = true;
            }
            res ++;
            visited[i] = true;
        }
        return res;
    }
    bool is_se(string& a, string& b) {
        if(a.size()!=b.size()) return false;
        vector<char> cs;
        for(char c: a) cs.push_back(c);
        for(int i=0;i<b.size();i++) {
            if(cs[i]!=b[i]) {
                bool swaped = false;
                for(int j=i+2;j<cs.size();j+=2) {
                    if(cs[j]==b[i]) {
                        char tmp = cs[i];
                        cs[i] = cs[j];
                        cs[j] = tmp;
                        swaped = true;
                    }
                }
                if(!swaped) return false;
            }
        }
        return true;
    }
};