#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
    long long n, m, p;
    cin>>n>>m>>p;
    vector<long long> a(n), b(m);
    for(int i=0;i<n;i++) scanf("%lld", &a[i]);
    for(int i=0;i<m;i++) scanf("%lld", &b[i]);
    vector<long long> sa(n+1, 0), sb(m+1, 0);
    for(int i=0;i<n;i++) sa[i+1] = (sa[i]+a[i])%p;
    for(int i=0;i<m;i++) sb[i+1] = (sb[i]+b[i])%p;
    long long res = 0;
    for(int i=0;i<n;i++) if(sa[i+1]!=0) {res+=i; break;}
    for(int i=0;i<m;i++) if(sb[i+1]!=0) {res+=i; break;}
    cout<<res<<endl;
    return 0;
}