#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int cnt[200001];
int main() {
    int t, n, a; cin>>t;
    while(t--) {
        cin>>n;
        memset(cnt, 0, sizeof(cnt));
        map<int, int> idx;
        for(int i=1;i<=n;i++) {
            cin>>a;
            cnt[a]++;
            if(cnt[a]==1) idx[a] = i;
            else if(cnt[a]==2) idx.erase(a);
        }
        cout<<(idx.empty()?-1:(idx.begin()->second))<<endl;
    }
    return 0;
}