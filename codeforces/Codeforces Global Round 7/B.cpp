#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    long n; cin>>n;
    vector<long> b(n), a(n);
    for(long& i: b) cin>>i;
    a[0] = 0;
    long ans = 0;
    for(int i=1;i<n;i++) {
        a[i] = ans + b[i];
        ans = max(ans, a[i]);
    }
    for(long i: a) cout<<(i+b[0])<<" ";
    cout<<endl;
    return 0;
}