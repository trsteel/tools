#include <iostream>
#include <unordered_set>
using namespace std;

long n, k, a[500001], b, maxx[500001];
long cal(long l, long r, long mi, long ma) {
    if(l>r) return 0;
    if(mi>ma) return -1;
    if(r-l<ma-mi) return -1;
    if(l==r) {
        return (a[l] >= mi && a[l] <= ma) ? 0 : 1;
    }
    maxx[l] = a[l];
    for(int i=l+1;i<=r;i++) maxx[i] = max(maxx[i-1], a[i]);
    long res = 0;
    if(a[r] <= maxx[r-1] && ma > maxx[r-1]) {
        
    }
    for(int i=r; i>l;i++) {

    }
}

int main(){
    
    cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    unordered_set<long> us;
    for(int i=0;i<k;i++) {
        cin>>b; us.insert(b);
    }
    long pre = INT_MIN, idx = -1, res = 0;
    for(int i=0;i<n;i++) {
        if(us.count(a[i])) {
            long ans = cal(idx+1, i-1, pre+1, a[i]-1);
            if(ans==-1) {res = ans; break;}
            res += ans;
            pre = a[i], idx = i;
        }
    }
    cout<<res<<endl;
    return 0;
}