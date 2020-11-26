#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

const long maxn = 200001;
long a[maxn];

struct Node {
    long l, r, mi;
    Node(long ll, long rr, long mii) {
        l = ll, r = rr, mi = mii;
    }
};

Node* seg[maxn*4];

void build(long v, long l, long r) {
    if(l==r) {
        seg[v] = new Node(l, r, a[l]);
        return;
    }
    long m = (l+r)>>1;
    build(v*2, l, m);
    build(v*2+1, m+1, r);
    seg[v] = new Node(l, r, min(seg[v*2]->mi, seg[v*2+1]->mi));
}

long query(long v, long l, long r) {
    if(l > r) return maxn;
    if(seg[v]->l==l && seg[v]->r==r) {
        return seg[v]->mi;
    }
    long m = (seg[v]->l + seg[v]->r) >> 1;
    if(r<=m) return query(v*2, l, r);
    if(l>m) return query(v*2+1, l, r);
    return min(query(v*2, l, m), query(v*2+1, m+1, r));
}

int main(){
    long t, n;
    cin>>t;
    while(t--) {
        cin>>n;
        vector<long> ma(n+1, 0);
        for(long i=1;i<=n;i++) {
            cin>>a[i]; ma[i] = max(ma[i-1], a[i]);
        }
        memset(seg, 0, sizeof(seg));
        build(1, 1, n);
        long ans = a[n];
        bool find = false;
        for(long i=n; i>2;i--) {
            ans = max(ans, a[i]);
            long l = lower_bound(ma.begin()+1, ma.end(), ans) - ma.begin();
            if (l >= i-1) continue;
            long r = upper_bound(ma.begin()+1, ma.end(), ans) - ma.begin() - 1;
            r = min(r, i-1);
//            cout<<ans<<" "<<l<<" "<<r<<endl;
            while(l<=r) {
                long mid = (l+r)>>1;
                long cur = query(1, mid+1, i-1);
//                cout<<ans<<" "<<(mid+1)<<" "<<(i-1)<<" "<<cur<<endl;
                if(cur == ans) {
                    cout<<"YES"<<endl;
                    cout<<mid<<" "<<(i-mid-1)<<" "<<(n-i+1)<<endl;
                    find = true; break;
                } else if(cur < ans) l = mid + 1;
                else r = mid - 1;
            }
            if(find) break;
        }
        if(!find) cout<<"NO"<<endl;
    }
    return 0;
}