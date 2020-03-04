#include <iostream>
#include <vector>
using namespace std;

void bfs(string& s, int i, int t, int ans, int& res) {
    if(i==s.size()-1) {
        if(s[i] != t-1+'a') ans++;
        if(t>=1 && t<=27) res = max(res, ans);
        return;
    }
    for(char c='a'; c<='z'; c++) {
        int d = s[i]==c ? 0 : 1;
        bfs(s, i+1, t-c+'a'-1, ans+d, res);
    }
}

int main(){
    int n; cin>>n;
    string s; cin>>s;
    int res = 0;
    bfs(s, 0, n, 0, res);
    cout<<res<<endl;
    return 0;
}