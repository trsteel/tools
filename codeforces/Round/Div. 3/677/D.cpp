#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int maxn = 5001;
long t, n, a[maxn];

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        unordered_map<long, vector<long>> um;
        for(int i=1;i<=n;i++) {
            cin>>a[i]; um[a[i]].push_back(i);
        }
        if(um.size()==1) {
            cout<<"NO"<<endl; continue;
        }
        cout<<"YES"<<endl;
        long start = -1, mi = n+1;
        for(auto& it: um) if(it.second.size()<mi) {
            start = it.first;
            mi = it.second.size();
            break;
        }
        auto v = um[start];
        um.erase(start);
        auto v1 = um.begin()->second;
        um.erase(um.begin());
        for(int i: v) cout<<i<<" "<<v1[0]<<endl;
        for(int i=1;i<v1.size();i++) cout<<v[0]<<" "<<v1[i]<<endl;
        long pre = v[0];
        for(auto& it: um) {
            for(int j: it.second) cout<<pre<<" "<<j<<endl;
        }
    }
    return 0;
}
