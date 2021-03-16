#include <iostream>
#include <algorithm>
using namespace std;

const long maxn = 200001;
long t, n, a[maxn];

bool cal() {
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a, a+n);
    long d = 0;
    for(int i=0;i<n;i++) {
        if(a[i]>i+1) return false;
        d += i+1-a[i];
    }
    return d%2==1;
}

int main() {
    cin>>t;
    while(t--) {
        cout<<(cal()?"First":"Second")<<endl;
    }
    return 0;
}
