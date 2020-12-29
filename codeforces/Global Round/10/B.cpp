#include <iostream>

using namespace std;
const long maxn = 200001;
long long t, n, k, a[maxn];

void cal() {
    long long ma = a[0];
    for(int i=1;i<n;i++) ma = max(ma, a[i]);
    for(int i=0;i<n;i++) a[i] = ma-a[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        cal();
        k--;
        if(k%2) cal();
        for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}