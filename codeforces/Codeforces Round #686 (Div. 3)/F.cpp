#include <iostream>
#include <vector>
#include <string.h>
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
        for(long i=1;i<=n;i++) cin>>a[i];
        memset(seg, 0, sizeof(seg));
        build(1, 1, n);
        long i = 1, j = n, mal = a[1], mar = a[n];
        bool find = false;
        while(i<j) {
            if(mal < mar) {mal = max(mal, a[++i]); continue;}
            if(mal > mar) {mar = max(mar, a[--j]); continue;}
            long ans = query(1, i+1, j-1);
            cout<<i<<" "<<j<<" "<<ans<<endl;
            if(ans==mal) {
                find = true; break;
            }
            mal = max(mal, a[++i]);
            mar = max(mar, a[--j]);
        }
        if(find) {
            cout<<"YES"<<endl<<i<<(j-i)<<(n-j-1)<<endl;
        } else cout<<"NO"<<endl;
    }
    return 0;
}