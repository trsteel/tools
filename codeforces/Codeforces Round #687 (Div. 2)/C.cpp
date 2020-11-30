#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

long t, n, p, k, x, y;
string s;

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>p>>k>>s>>x>>y;
        vector<long> cnt(k, 0);
        for(int i=0;i<n;i++) if(s[i]=='0') {
            if(i+1 >= p) cnt[(i+1)%k]++;
        }
        long res = INT_MAX;
        for(long i=p;i<=n;i++) {
            res = min(res, (i-p)*y+cnt[i%k]*x);
            if(s[i-1]=='0') cnt[i%k]--;
        }
        cout<<res<<endl;
    }
    return 0;
}