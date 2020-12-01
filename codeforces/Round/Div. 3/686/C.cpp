#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<int, int> um;
    int t, n, a[200001];
    cin>>t;
    while(t--) {
        um.clear();
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        um[a[0]] = 1;
        for(int i=1;i<n;i++) {
            if(a[i-1]!=a[i]) um[a[i]]++;
        }
        int res = n+1;
        for(auto& it: um) {
            int i = it.first, ans = it.second;
            if(i!=a[n-1]) ans++;
            if(i==a[0]) ans--;
            res = min(res, ans);
        }
        cout<<res<<endl;
    }
    return 0;
}