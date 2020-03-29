#include <iostream>
#include <vector>
#include <set>
using namespace std;

long long query(long long x) {
    cout<<1<<" "<<x<<endl;
    cin>>x;
    return x;
}

int main(){
    long t, n; cin>>t;
    while(t--) {
        cin>>n;
        vector<long long> a(n);
        a[0] = query(0);
        a[n-1] = query((1LL<<60)-1);
        for(long i=n-2;i>0;i--) {
            long long pre = a[i+1], ans = 0;
            for(long b=59; b>=0; b--) if((pre>>b)&1LL) {
                long long tmp = query(ans|(1LL<<b));
                if(tmp!=pre) {ans |= 1LL<<b; continue;}
                a[i] = b==0 ? ans : query(ans|((1LL<<b)-1));
                break;
            }
        }
        cout<<"2 ";
        for(long long i: a) cout<<i<<" ";
        cout<<endl; cin>>n;
    }
    return 0;
}