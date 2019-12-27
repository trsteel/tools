#include <iostream>
#include <vector>
using namespace std;

int cal(int n) {
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 5;
    int mod = 10000;
    vector<int> a(2, 0), b(2, 0), c(2, 0);
    a[0] = 1, a[1] = 1, b[0] = 2, b[1] = 2;
    for(int i=3;i<=n;i++) {
        c[0] = (a[1]*2+a[0]+b[0])%mod;
        c[1] = (b[0]+b[1])%mod;
        a[0] = b[0], a[1] = b[1];
        b[0] = c[0], b[1] = c[1];
    }
    return c[0];
}

int main(){
    int n; cin>>n;
    cout<<cal(n)<<endl;
    return 0;
}