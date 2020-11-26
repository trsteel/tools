#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const long long maxn = 200001;
long long a[maxn], n, q, t, x, y;

struct Node {
    long long l, r, mi, ma, sum, lazy;
    Node(long long ll, long long rr, long long val) {
        l = ll, r = rr, lazy = 0;
        mi = ma = sum = val;
    }
};

Node* seg[4*maxn];

void push_up(long long v) {
    seg[v]->mi = min(seg[v*2]->mi, seg[v*2+1]->mi);
    seg[v]->ma = max(seg[v*2]->ma, seg[v*2+1]->ma);
    seg[v]->sum = seg[v*2]->sum + seg[v*2+1]->sum;
}

void push_down(long long v) {
    if(seg[v]->l == seg[v]->r) return;
    if(seg[v]->lazy == 0) return;
    long long lazy = seg[v]->lazy;
    seg[v]->lazy = 0;
    seg[v*2]->mi = seg[v*2]->ma = seg[v*2]->lazy = lazy;
    seg[v*2]->sum = lazy*(seg[v*2]->r-seg[v*2]->l+1);
    seg[v*2+1]->mi = seg[v*2+1]->ma = seg[v*2+1]->lazy = lazy;
    seg[v*2+1]->sum = lazy*(seg[v*2+1]->r-seg[v*2+1]->l+1);
}

void build(long long v, long long l, long long r) {
    if(l==r) {seg[v] = new Node(l, r, a[l]); return;}
    long long m = (l+r)>>1;
    build(v*2, l, m);
    build(v*2+1, m+1, r);
    seg[v] = new Node(l, r, 0);
    push_up(v);
}

void update(long long v, long long l, long long r, long long val) {
    if (seg[v]->l>r || seg[v]->r<l || seg[v]->mi>=val) return;
    if(seg[v]->l>=l && seg[v]->r<=r && seg[v]->ma<val) {
        seg[v]->mi = seg[v]->ma = seg[v]->lazy = val;
        seg[v]->sum = val * (seg[v]->r-seg[v]->l+1);
        return;
    }
    push_down(v);
    update(v*2, l, r, val);
    update(v*2+1, l, r, val);
    push_up(v);
}

long long query(long long v, long long l, long long r, long long& val) {
    if(seg[v]->mi > val) return 0;
    if(seg[v]->l>r||seg[v]->r<l) return 0;
    if(seg[v]->l>=l&&seg[v]->r<=r&&seg[v]->sum<=val) {
        val -= seg[v]->sum; return seg[v]->r-seg[v]->l+1;
    }
    push_down(v);
    return query(v*2, l, r, val) + query(v*2+1, l, r, val);
}

int main(){
    cin>>n>>q;
    for(long long i=1;i<=n;i++) cin>>a[i];
    build(1, 1, n);
    while(q--) {
        cin>>t>>x>>y;
        if(t==1) {
            update(1, 1, x, y); continue;
        }
        cout<<query(1, x, n, y)<<endl;
    }
    return 0;
}