#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool match(string& s, int l, int r) {
    while(l<r && s[l]==s[r]) l++, r--;
    return l>=r;
}

string kmp(string s) {
    int n = s.size(), j=0;
    vector<int> next(n, 0);
    for(int i=1;i<n;i++) {
        while(j&&s[i]!=s[j]) j = next[j-1];
        if(s[i]==s[j]) j++;
        next[i] = j;
    }
    return s.substr(0, j);
}

void dfs(string& s, int l, int r) {
    if(l>=r) {cout<<s<<endl; return;}
    if(s[l]==s[r]) { dfs(s, l+1, r-1); return;}
    string ans = s.substr(l, r-l+1);
    string rvt = ans;
    reverse(rvt.begin(), rvt.end());
    string ans1 = kmp(ans+"#"+rvt), ans2 = kmp(rvt+"#"+ans);
    cout<<s.substr(0, l)<<(ans1.size()>ans2.size()?ans1:ans2)<<s.substr(r+1)<<endl;
}

int main(){
    long t; cin>>t;
    string s;
    while(t--) {
        cin>>s;
        dfs(s, 0, s.size()-1);
    }
    return 0;
}