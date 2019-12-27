#include <iostream>
#include <vector>
using namespace std;
string cal(string& s) {
    int n = s.size();
    for(int i=n-1;i>=0;i--) {
        if(s[i]=='9') continue;
        vector<bool> vis(10, false);
        bool valid = true;
        for(int j=0;j<i;j++) {
            if(vis[s[j]-'0'] || s[j]=='0') {valid = false; break;}
            vis[s[j]-'0'] = true;
        }
        if(!valid) continue;
        char c = s[i] + 1;
        while(c<='9' && vis[c-'0']) c++;
        if(c>'9') continue;
        s[i] = c;
        vis[s[i]-'0'] = true;
        while(++i<n) {
            for(char c='1'; c<='9'; c++) {
                if(vis[c-'0']) continue;
                vis[c-'0'] = true;
                s[i] = c;
                break;
            }
        }
        return s;
    }
    if(n==9) return "0";
    string res = "";
    for(int i=0;i<=n;i++) {
        res += char(i+1+'0');
    }
    return res;
}

int main(){
    string s; cin>>s;
    cout<<cal(s)<<endl;
    return 0;
}