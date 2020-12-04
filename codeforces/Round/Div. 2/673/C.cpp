#include <iostream>
#include <vector>
using namespace std;

int main(){
    long t, n, a[300001], k[300001];
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        vector<long> pre(n+1, -1), dis(n+1, 0);
        for(int i=0;i<n;i++) {
            dis[a[i]] = max(dis[a[i]], i-pre[a[i]]);
            pre[a[i]] = i;
        }
        for(int i=0;i<=n;i++) {
            dis[i] = max(dis[i], n-pre[i]);
            // cout<<i<<" "<<dis[i]<<endl;
        }
        vector<long> res(n+1, -1);
        for(int i=0;i<=n;i++) {
            if(res[dis[i]]==-1 || res[dis[i]] > i) {
                res[dis[i]] = i;
            }
        }
        long last = -1;
        for(int i=1;i<=n;i++) {
            if(res[i] != -1 && (last==-1 || res[i] < last)) last = res[i];
            cout<<last<<" ";
        }
        cout<<endl;
    }
    return 0;
}