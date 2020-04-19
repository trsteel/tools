#include <iostream>
#include <string.h>
using namespace std;

pair<bool, string> find(string& a, string& b, long x, long y) {
    if(x==a.size()||y==b.size()) {
        bool valid = x==a.size()&&y==b.size();
        return make_pair(valid, "");
    }
    if(a[x]==b[y]||a[x]=='*'||b[y]=='*') {
        auto p = find(a, b, x+1, y+1);
        if(p.first) {
            string res = p.second;
            char c = a[x]=='*'?b[y]:a[x];
            res.insert(res.begin(), c);
            return make_pair(true, res);
        }
    }
    if(a[x]=='*'||b[y]=='*') {
        auto p = find(a, b, x, y+1);
        if(p.first) {
            string res = p.second;
            char c = a[x]=='*'?b[y]:a[x];
            res.insert(res.begin(), c);
            return make_pair(true, res);
        }
        p = find(a, b, x+1, y);
        if(p.first) {
            string res = p.second;
            char c = a[x]=='*'?b[y]:a[x];
            res.insert(res.begin(), c);
            return make_pair(true, res);
        }
    }
    return make_pair(false, "");
}

int main(){
    long long T, n; cin>>T;
    string s;
    for(long long t=1;t<=T;t++) {
        cin>>n;
        string ans="*";
        for(long i=0;i<n;i++) {
            cin>>s; ans = find(s, ans, 0, 0).second;
            // cout<<i<<" "<<s<<" "<<ans<<endl;
        }
        string res = "";
        if (ans.empty()) res = "*";
        else {
            for(char c: ans) if(c!='*') res.push_back(c);
            if(res.empty()) res = "A";
        }
        if(res.size()>10000) res = "*";
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
    return 0;
}