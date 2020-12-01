#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

const long maxn = 500001;
long n, k, a[maxn], b, v[maxn], sta[maxn];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i]; a[i] -= i;
        sta[i] = INT_MAX;
    }
    for(int i=0;i<k;i++) {
        cin>>b; v[b] = 1;
    }
    b = INT_MIN;
    long res = 0, top = 0;
    for(int i=1;i<=n;i++) {
        if(a[i] >= b) {
            long p = upper_bound(sta+1, sta+n+1, a[i])-sta;
            if(v[i]) {
                res += p;
                while(top) sta[top--] = INT_MAX;
                b = a[i];
            } else {
                sta[p] = a[i];
                top = max(top, p);
            }
        } else if(v[i]) {
            cout<<-1<<endl;
            return 0;
        }
    }
    res += top;
    cout<<(n-res)<<endl;
    return 0;
}