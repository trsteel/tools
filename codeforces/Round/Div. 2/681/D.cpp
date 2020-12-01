#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long t, n, a[30001];

bool cal() {
    long c = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i] > a[i - 1])
            c += a[i] - a[i - 1];
    }
    return c <= a[n-1];
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        for(long long i=0;i<n;i++) cin>>a[i];
        cout<<(cal()?"YES":"NO")<<endl;
     }
    return 0;
}