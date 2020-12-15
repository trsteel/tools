#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n, x, y;
    cin>>n;
    vector<long> res(n+1, 0);
    vector<bool> vis(n+1, false);
    long i = 1;
    for(long j = 2; j <= n; j++) {
        cout<<"? "<<i<<" "<<j<<endl;
        cout.flush(); cin>>x;
        cout<<"? "<<j<<" "<<i<<endl;
        cout.flush(); cin>>y;
        if(x > y) {
            res[i] = x; i=j; vis[x] = true;
        } else {
            res[j] = y; vis[y] = true;
        }
    }
    for(long i=1;i<=n;i++) if(!vis[i]) {
        x = i; break;
    }
    for(long i=1;i<=n;i++) if(res[i]==0) {
        res[i] = x; break;
    }
    cout<<"! ";
    for(long i=1;i<=n;i++) cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}
