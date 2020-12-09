#include <iostream>

using namespace std;

long t, n, x, a[501];

long cal() {
    long p = 0, ans = 0;
    for(int i=n;i>=1&&!p;i--)if(a[i]<a[i-1])p=i;
    for(int i=1;i<=p;i++)if(x<a[i])swap(x,a[i]),ans++;
    p=0;
    for(int i=n;i>=1&&!p;i--)if(a[i]<a[i-1])p=i;
    return p ? -1 : ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin>>t;
    while(t--) {
        cin>>n>>x;
        for(int i=1;i<=n;i++) cin>>a[i];
        cout<<cal()<<endl;
    }
    return 0;
}