#include <iostream>

using namespace std;
const long maxn = 200001;
long long t, n, k, h[maxn];

bool cal() {
    long long l=h[0], r=h[0];
    bool ans = true;
    for(int i=1;i<n;i++) {
        long long x = h[i];
        ans&=(x+k-1+k>l&&r+k>x);
        l=max(l-k+1,x),r=min(r+k-1,x+k-1);
    }
    return ans && (l==h[n-1]);
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;i++) {
            cin>>h[i];
        }
        cout<<(cal()?"Yes":"No")<<endl;
    }
    return 0;
}