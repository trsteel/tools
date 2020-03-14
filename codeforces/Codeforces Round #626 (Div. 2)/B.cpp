#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long cal(vector<long>& suma, vector<long>& sumb, long long x, long long y) {
    long long n = suma.size()-1, m = sumb.size()-1;
    long long a = 0, b = 0;
    for(long i=0;i<=n-x;i++) if(suma[i+x]-suma[i]==x) a++;
    for(long j=0;j<=m-y;j++) if(sumb[j+y]-sumb[j]==y) b++;
    return a*b;
}

int main(){
    long long n, m, k;
    cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int& i: a) cin>>i;
    for(int& i: b) cin>>i;
    vector<long> suma(n+1, 0), sumb(m+1, 0);
    for(long i=0;i<n;i++) suma[i+1] = suma[i]+a[i];
    for(long i=0;i<m;i++) sumb[i+1] = sumb[i]+b[i];
    long long res = 0;
    for(long long i=1; i<=sqrt(k); i++) {
        if(k%i) continue;
        res += cal(suma, sumb, i, k/i);
        if(i*i<k) res += cal(suma, sumb, k/i, i);
    }
    cout<<res<<endl;
    return 0;
}