#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long t, n, k, a[200001];
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        long long res = 0;
        for(int i=0;i<=k;i++) res += a[n-1-i];
        cout<<res<<endl;
    }
    return 0;
}