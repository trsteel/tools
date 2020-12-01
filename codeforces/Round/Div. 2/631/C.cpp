#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n, m, sum=0; cin>>n>>m;
    vector<long long> l(m);
    for(long long& i: l) {
        cin>>i; sum += i;
    }
    vector<long long> res(m);
    long long idx = 0;
    for(long long i=0;i<m;i++) {
        res[i] = idx+1; sum -= l[i];
        if(idx+l[i]>n) break;
        for(long long j=1;j<=l[i];j++) {
            idx++; if(idx+sum>=n) break;
        }
        if(idx+sum<n) break;
    }
    if(sum!=0||idx!=n) cout<<-1<<endl;
    else for(long long i: res) cout<<i<<" ";
    return 0;
}