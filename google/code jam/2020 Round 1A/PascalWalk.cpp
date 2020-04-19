#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool vis[10000];

void find(long long n) {
    long long k=0;
    while(((1LL<<(k+1))+k+1)<=n) k++;
    long long d = n-k-(1LL<<k);
    if(d<=0) return;
    // cout<<n<<" "<<k<<" "<<d<<endl;
    for(long long i=0;i<60;i++) {
        if((1LL<<i)&d) vis[i] = true;
    }
    vis[k] = true;
}

int main(){
    long long T, n; cin>>T;
    string s;
    for(long long t=1;t<=T;t++) {
        cin>>n;
        cout<<"Case #"<<t<<": "<<endl;
        memset(vis, 0, sizeof(vis));
        find(n);
        bool left = true;
        long long i=0, x, y;
        while(n>0) {
            // cout<<n<<" "<<i<<endl;
            if(!vis[i]) {
                x = i+1, y = left?1:(i+1);
                cout<<x<<" "<<y<<endl;
                n--;
            } else {
                if(left) for(y=1;y<=i+1;y++) cout<<(i+1)<<" "<<y<<endl;
                else for(y=i+1;y>=1;y--) cout<<(i+1)<<" "<<y<<endl;
                left = !left;
                n -= 1<<i;
            }
            i++;
        }
    }
    return 0;
}