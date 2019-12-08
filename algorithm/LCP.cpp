#include <iostream>
#include <vector>

using namespace std;

vector<int> LCP(string& s) {
    int n = s.size();
    // 后缀数组
    vector<int> sa(n, 0);
    for(int i=0;i<n;i++) sa[i] = i;
    sort(sa.begin(), sa.end(), [&s](int i, int j) {
        while(i<s.size() && j<s.size()) {
            if(s[i]==s[j]) { i++; j++; continue; }
            return s[i]<s[j];
        }
        return i==s.size() ? true : false;
    });
    // LCP
    vector<int> rank(n,0);
    for(int i=0; i<n; i++) rank[sa[i]]=i;
    vector<int> lcp(n,0);
    for(int i=0, k=0; i<n; i++, k?k--:0) {
        if(rank[i]==n-1) {k=0; continue;}
        int j=sa[rank[i]+1];
        while(i+k<n && j+k<n && s[i+k]==s[j+k]) k++;
        lcp[rank[i]]=k;
    }
    return lcp;
}

int main() {
    string s; cin>>s;
    auto lcp = LCP(s);
    for(int i: lcp) cout<<i<<" ";
    cout<<endl;
    return 0;
}