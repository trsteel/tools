#include <iostream>

using namespace std;

string dfs(string& s, char ch, int l, int r) {
    // cout<<ch<<" "<<l<<" "<<r<<endl;
    string res = "";
    if(l==r) {
        for(char c=ch; c<s[l];c++) res += '(';
        res += s[l];
        for(char c=ch; c<s[l];c++) res += ')';
        return res;
    }
    while(l<=r&&s[l]==ch) res += s[l++];
    if(l>r) return res;
    int pre = l;
    for(int i=l;i<=r;i++) if(s[i]==ch) {
        if(pre<i) res += "(" + dfs(s, ch+1, pre, i-1) + ")";
        res += s[i], pre = i+1;
    }
    if(pre<=r) res += "(" + dfs(s, ch+1, pre, r) + ")";
    return res;
}

int main(){
    long long T; cin>>T;
    string s;
    for(long long t=1;t<=T;t++) {
        cin>>s;
        cout<<"Case #"<<t<<": "<<dfs(s, '0', 0, s.size()-1)<<endl;
    }
    return 0;
}