#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
long t, n;
string s;

void solve() {
    vector<long> res(n, 0);
    long mai = 0;
    unordered_set<long> pre0, pre1;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') {
            if(pre1.empty()) {
                pre1.insert(++mai);
            }
            long j = *pre1.begin();
            pre1.erase(j);
            pre0.insert(j);
            res[i] = j;
        } else {
            if(pre0.empty()) {
                pre0.insert(++mai);
            }
            long j = *pre0.begin();
            pre0.erase(j);
            pre1.insert(j);
            res[i] = j;
        }
        // cout<<i<<" "<<pre0<<" "<<pre1<<endl;
    }
    cout<<mai<<endl;
    for(long i: res) cout<<i<<" ";
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>s;
        solve();
    }
    return 0;
}