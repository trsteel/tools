#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cal(string& s, vector<int>& p) {
    sort(p.begin(), p.end());
    int n = s.size(), m = p.size();
    p.push_back(n-1);
    vector<int> multi(n, 0);
    for(int i=0, idx=0; i<n; i++) {
        while(i>p[idx]) idx++;
        multi[i] = m-idx+1;
    }
    vector<int> cnt(26, 0);
    for(int i=0;i<n;i++) cnt[s[i]-'a']+=multi[i];
    return cnt;
}

int main(){
    int t, n, m, num; cin>>t;
    string s;
    while(t--) {
        cin>>n>>m>>s;
        vector<int> p(m);
        for(int i=0;i<m;i++) {cin>>num;p[i]=num-1;}
        for(int i: cal(s, p)) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}