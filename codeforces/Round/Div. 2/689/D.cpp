#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

long long t, n, a[100002], sum[100002], s, q;
unordered_set<long long> us;

void find(long l, long r) {
    us.insert(sum[r+1]-sum[l]);
    if(l == r || a[l]==a[r]) return;
    long mid = (a[l]+a[r])/2;
    long idx = upper_bound(a+l, a+r+1, mid) - a;
    find(l, idx-1), find(idx, r);
}

int main(){
    cin>>t;
    while(t--) {
        cin>>n>>q;
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a, a+n);
        sum[0] = 0;
        for(int i=0;i<n;i++) {
            sum[i+1] = sum[i] + a[i];
        }
        us.clear();
        find(0, n-1);
        while(q--) {
            cin>>s;
            cout<<(us.count(s) ? "Yes" : "No")<<endl;
        }
    }
    return 0;
}