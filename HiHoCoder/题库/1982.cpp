#include <iostream>
#include <vector>

using namespace std;

void process(string& s, int l, int r) {
    if(l==r) {
        vector<int> cnt(10, 0);
        for(char c: s) if(++cnt[c-'0']>1) return;
        int n = s.size();
        swap(s[n-2], s[n-1]);
        return;
    }
    int k = r;
    for(int i=r-1;i>=l;i--) if(s[i]>s[k]) k=i;
    int ans = l;
    while(k>ans&&s[ans]==s[k]) ans++;
    if(k>ans) {swap(s[ans], s[k]); return;}
    process(s, l+1, r);
}

int main(){
    string s; cin>>s;
    process(s, 0, s.size()-1);
    cout<<s<<endl;
    return 0;
}