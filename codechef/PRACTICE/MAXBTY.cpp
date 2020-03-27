/**
 * 线段树模板
 **/
#include <iostream>
#include <vector>
using namespace std;

const long long maxn = 100010;

long long pos[maxn];

struct Node {
    long long pre, sum, suf;
} tree[4*maxn];

void merge(Node& a, Node& b, Node& c) {
    c.sum = a.sum + b.sum;
    c.pre = max(a.pre, a.sum+b.pre);
    c.suf = max(b.suf, a.suf+b.sum);
}

void build(vector<long long>& vec, long long id, long long l, long long r) {
    if(l==r) {
        tree[id].pre = tree[id].sum = tree[id].suf = vec[l];
        pos[l] = id;
        return;
    }
    long long mid = (l+r)>>1;
    build(vec, id*2+1, l, mid);
    build(vec, id*2+2, mid+1, r);
    merge(tree[id*2+1], tree[id*2+2], tree[id]);
}

void update(long long id, long long value) {
    long long ans = pos[id];
    tree[ans].sum = tree[ans].pre = tree[ans].suf = value;
    id = ans;
    do {
        id = (id-1)/2;
        merge(tree[id*2+1], tree[id*2+2], tree[id]);
    } while(id!=0);
}

Node query(long long id, long long b, long long e, long long l, long long r) {
    Node res;
    res.sum = res.pre = res.suf = -1;
    if(b>r||e<l) return res;
    if(b>=l&&e<=r) return tree[id];
    long long mid = (b+e)>>1;
    if(l>mid) return query(id*2+2, mid+1, e, l, r);
    if(r<=mid) return query(id*2+1, b, mid, l, r);
    Node left = query(2*id+1, b, mid, l, r);
    Node right = query(2*id+2, mid+1, e, l, r);
    merge(left, right, res);
    return res;
}

int main(){
    long long t, n, q, x, y; cin>>t;
    char c;
    while(t--) {
        cin>>n>>q;
        vector<long long> vec(n);
        for(long long& i: vec) cin>>i;
        build(vec, 0, 0, n-1);
        while(q--) {
            cin>>c>>x>>y;
            x--, y--;
            if(c=='U') {
                vec[x] = y+1; update(x, y+1); continue;
            }
            long long ans = query(0, 0, n-1, x, y).sum;
            if(x>0) ans += max(0LL, query(0, 0, n-1, 0, x-1).suf);
            if(y<n-1) ans += max(0LL, query(0, 0, n-1, y+1, n-1).pre);
            cout<<ans<<endl;
        }
    }
    return 0;
}