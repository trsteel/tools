class Solution {
public:
    string pushDominoes(string dominoes) {
        int last = -1;
        vector<char> ans(dominoes.size(), '.');
        for(int i=0;i<dominoes.size();i++) {
            ans[i] = dominoes[i];
            if(last!=-1 && dominoes[last]=='R') ans[i] = 'R';
            if(dominoes[i]=='.') continue;
            if(dominoes[i]=='R') {
                last = i;
                continue;
            }
            if(last == -1 || dominoes[last]=='L') {
                for(int j=max(last, 0);j<=i;j++) ans[j]='L';
            } else {
                int m = (last+i+1)>>1;
                for(int j=last;j<=i;j++) {
                    if(j<m) ans[j]='R';
                    else if(j==m) {
                        ans[j] = (last+i+1)%2 ? '.': 'L';
                    } else {
                        ans[j] = 'L';
                    }
                }
            }
            last = i;
        }
        if(last!=-1 && dominoes[last]=='R') {
            for(int i=last;i<dominoes.size();i++) 
                ans[i] = 'R';
        }
        string s;
        for(auto c: ans) s+=c;
        return s;
    }
};