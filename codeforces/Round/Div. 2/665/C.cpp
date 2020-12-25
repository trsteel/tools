#include <iostream>
#include <algorithm>
using namespace std;
long t, n, a[100001], b[100001];

long gcd(long a,long b){
    if(b==0) return a;
    return gcd(b,a%b);
}

bool cal() {
    cin>>n;
    long mi = 1e9 + 7;
    for(int i=0;i<n;i++) {
        cin>>a[i]; b[i] = a[i];
    }
    sort(b, b+n);
    long g = -1;
    for(int i=0;i<n;i++) if(a[i]!=b[i]) {
        if(a[i]%b[0]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--) {
        cout<<(cal()?"YES":"NO")<<endl;
    }
    return 0;
}